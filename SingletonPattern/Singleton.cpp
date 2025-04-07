#include "mutex"
#include "iostream"

using namespace std;

class singleton{
    private:
        static singleton* instance;
        static mutex mutex_x;
        singleton() = default;

    public:
        static singleton* getInstance(){
            std::lock_guard<std::mutex> lock(mutex);
            if(instance == nullptr)
            {
                instance = new singleton();
                cout << "Creating the singleton object" << endl;
            }
            return instance;
        }

        singleton(const singleton&) = delete;
        singleton operator=(const singleton&) = delete;
        singleton(const singleton&&) = delete;
        singleton operator=(const singleton&&) = delete;

        ~singleton()
        {
            delete instance;
            instance = nullptr;
        }
};

singleton* singleton::instance = nullptr;
std::mutex singleton::mutex_x;

int main()
{
    singleton* obj = singleton::getInstance();
    singleton* obj1 = singleton::getInstance();
}