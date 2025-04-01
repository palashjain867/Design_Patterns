#include "iostream"

using namespace std;

class myObserver{

    public:
    virtual void update() = 0;

    void addObserver(){

    }

    void removeObserver(){

    }

    void notifyObservers(){

    }
};

class concreteObserver : public myObserver{

    public:
        void update(){
            cout << "Update function of the concreteObserver class" << endl;
        }

};

int main()
{
    
    return 0;
}