
#include "iostream"

using namespace std;

class myStrategyPayment{
    public:
        virtual void execute() = 0; 
        ~myStrategyPayment(){

        }
};

class CreditCardPayment : public myStrategyPayment{
    public:
        void execute(){
            cout<<"Executing Credit card payment" << "\n";
        }
    
        CreditCardPayment(){

        }
        ~CreditCardPayment(){

        } //what should be the definitions of these

};

class PaypalPayment : public myStrategyPayment{
    public:
        void execute(){
            cout<<"Executing PayPal Payment " << "\n";
        }

        PaypalPayment(){

        }
        ~PaypalPayment(){

        }
};

class myContext{
    public:
    myStrategyPayment* myStrategyPtr;

    void setStrategy(myStrategyPayment* ptr){
        myStrategyPtr = ptr;
    }

    void executeStrategy()
    {
        myStrategyPtr->execute();
    }
};

int main()
{

    //Implement with smart pointers and function pointer
    
    myContext obj;
    myStrategyPayment* ptr = new PaypalPayment();
    obj.setStrategy(ptr);
    obj.executeStrategy();

    delete ptr;

    ptr = new CreditCardPayment();
    obj.setStrategy(ptr);
    obj.executeStrategy();

    delete ptr;
    
    return 0;
}