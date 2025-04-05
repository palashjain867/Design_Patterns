#include "string"
#include "iostream"
#include "memory"

using namespace std;

class Car{
    protected:
        int numSeats{0};
        std::string type;
    public:
        virtual void carFeatures() = 0;
        virtual ~Car() = default;
};

class Sedan : public Car{
    public:
        Sedan(){
            type = "Sedan";
            numSeats = 5;
        }
        void carFeatures() override{
            cout << "This is a Sedan. Car type: " << type << ", Seats: " << numSeats << endl;
        }
};

class SUV : public Car{
    public:
        SUV(){
            type = "SUV";
            numSeats = 8;
        }
        void carFeatures() override{
            cout << "This is a SUV. Car type: " << type << ", Seats: " << numSeats << endl;
        }
};

class CarFactory{
    public:
    static unique_ptr<Car>createCar(const string& type){
        if(type == "Sedan"){
            return make_unique<Sedan>();
        }
        else if(type == "SUV"){
            return make_unique<SUV>();
        }
        else{
            cout << "Car type doesnot exist " << endl;
            return nullptr;
        }
    }
};

int main()
{
    CarFactory factoryObj;
    unique_ptr<Car> myCar = factoryObj.createCar("SUV");
    myCar->carFeatures();
    myCar = factoryObj.createCar("Sedan");
    myCar->carFeatures();
}
