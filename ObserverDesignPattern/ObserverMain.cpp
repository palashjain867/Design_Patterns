#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class observer{
public:
    virtual void update() = 0;
    virtual ~observer() = default;
};

class subjectObserver{
    std::vector<observer*> observerList;

public:
    void addObserver(observer* obj){
        observerList.push_back(obj);
    }

    void removeObserver(observer* obj){
        observerList.erase(std::remove(observerList.begin(), observerList.end(), obj), observerList.end());
    }

    void notifyObservers(){
        for(observer* obs : observerList){
            obs->update();
        }
    }

};

class concreteObserver1: public observer{
    public:
        void update() override{
            cout << "Update function of the concreteObserver1 class" << endl;
        }

};

class concreteObserver2: public observer{

    public:
        void update() override{
            cout << "Update function of the concreteObserver2 class" << endl;
        }

};

class concretesubject1: public subjectObserver{
public:
    void notifyObservers()
    {
        subjectObserver::notifyObservers();
    }

};


int main()
{
    concretesubject1 subobj;
    concreteObserver1 obj1;
    concreteObserver2 obj2;

    subobj.addObserver(&obj1);
    subobj.addObserver(&obj2);

    cout << "Triggering notifications" << endl;
    subobj.notifyObservers();

    cout << "Removing observer 1 then notifying" << endl;
    subobj.removeObserver(&obj1);
    subobj.notifyObservers();
    
    return 0;
}