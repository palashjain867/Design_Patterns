#include "iostream"
#include "vector"
#include "algorithm"
#include "memory"
#include "mutex"

using namespace std;
std::mutex mtx;

class subscriber{
public:
    virtual void update(const string& videoTitle) = 0;
    virtual ~subscriber() = default;
};

class YoutubeChannel{
    std::vector<weak_ptr<subscriber>> subscribers;
    const string& channelName;

public:

    YoutubeChannel(const string& name) : channelName(name){}

    void subscribe(shared_ptr<subscriber> sub){
        std::lock_guard<std::mutex> lock(mtx);
        subscribers.push_back(sub);
    }

    void unsubscribe(shared_ptr<subscriber> sub){
        std::lock_guard<std::mutex> lock(mtx);
        subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(),
        [&sub](const weak_ptr<subscriber>& wptr){
            auto sptr = wptr.lock();
            return sptr == sub;
        }),
        subscribers.end());
    }

    void notifyObservers(const string& videoTitle){
        std::lock_guard<std::mutex> lock(mtx);
        for(auto it = subscribers.begin(); it != subscribers.end();)
        {
            if(auto ptr = it->lock()){
                ptr->update(videoTitle);
                ++it;
            }
            else{
                it = subscribers.erase(it); // remove the expired subscriber
            }
        }
    }

};

class SubscriberA: public subscriber{
    public:
        void update(const string& videoTitle) override{
            cout << "Notifying SubscriberA : New video upload - " << videoTitle << endl;
        }

};

class SubscriberB: public subscriber{
    public:
         void update(const string& videoTitle) override{
            cout << "Notifying SubscriberB : New video upload - " << videoTitle << endl;
        }

};

int main()
{
    YoutubeChannel channel("MagicBeast");
    auto subA = make_shared<SubscriberA>();
    auto subB = make_shared<SubscriberB>();

    channel.subscribe(subA);
    channel.subscribe(subB);

    cout << "Triggering notifications" << endl;
    channel.notifyObservers("New video has been uploaded");

    cout << "Removing observer 1 then notifying" << endl;
    channel.unsubscribe(subA);
    channel.notifyObservers("New video2 has been uploaded");
    
    return 0;
}