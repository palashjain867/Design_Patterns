//To implement the Builder Design Pattern in C++

#include <iostream>
using namespace std;

//Step 1. Define the Product (Complex Object)
// 		○ Create a class (e.g., Car) that represents the complex object to be built.
// 		○ Include multiple attributes (e.g., engine type, number of seats, GPS system, etc.).
// 		○ Provide setter methods for setting individual attributes.

class Car
{
    private:
        string engine;
        int seats;
        bool gps;

    public:
        void setEngine(const string& engineType) //why prefer const reference
        {
            engine = engineType;
        }

        void setSeats(int numSeats)
        {
            seats = numSeats;
        }

        void setGPS(bool hasGPS)
        {
            gps = hasGPS;
        }
};

//Step 2: Create the Builder Interface (Abstract Class)
// ○ Define a Builder class with pure virtual methods for setting each attribute of the Car class.
// ○ Include a virtual method getResult() that returns the fully constructed object.

class CarBuilder{
    public:
        virtual void setEngine(const string& engineType) = 0;
        virtual void setSeats(int numSeats) = 0;
        virtual void setGPS(bool hasGPS) = 0;
        virtual Car* getCar() = 0;
};

// Step 3: Implement Concrete Builders
// 		○ Create one or more concrete builder classes (e.g., SportsCarBuilder, SUVBuilder) that implement the Builder interface.
// 		○ Implement step-by-step construction methods that modify the internal Car object.
// 		○ Implement getResult() to return the fully built Car object.

class SportsCarBuilder : public CarBuilder
{
    Car* car;
    public:
        SportsCarBuilder(){
            car = new Car();
        }

        void setEngine(const string& engineType) override
        {
            car->setEngine(engineType);
        }
        void setSeats(int numSeats) override
        {
            car->setSeats(numSeats);
        }
        void setGPS(bool hasGPS) override
        {
            car->setGPS(hasGPS);
        }
        Car* getCar() override
        {
            return car;
        }
};

class SUVBuilder : public CarBuilder
{
    Car* car;
    public:
        SUVBuilder()
        {
                car = new Car();
        }

        void setEngine(const string& engineType) override
        {
            car->setEngine(engineType);
        }
        void setSeats(int numSeats) override
        {
            car->setSeats(numSeats);
        }
        void setGPS(bool hasGPS) override
        {
            car->setGPS(hasGPS);
        }
        Car* getCar() override
        {
            return car;
        }
};

// Step 4. Create the Director Class (Optional but Recommended)
// 		○ Define a Director class that controls the construction process.
// 		○ The Director receives a Builder object and calls the builder’s methods in a specific sequence.
// 		○ This ensures consistent object creation and enforces construction rules.

class Director
{
    CarBuilder* carBuilder;
    public:
        void setBuilder(CarBuilder* builder)
        {
            carBuilder = builder;
        }
        Car* getCar()
        {
            return carBuilder->getCar();
        }

        void constructSportsCar()
        {
            carBuilder->setEngine("v8");
            carBuilder->setSeats(2);
            carBuilder->setGPS(true);
        }

        void constructSUV()
        {
            carBuilder->setEngine("v6");
            carBuilder->setSeats(7);
            carBuilder->setGPS(false);
        }
};

// Step 6. Test the Implementation
// 		○ Create an instance of ConcreteBuilder.
// 		○ Pass it to the Director (if used) or call builder methods directly.
// 		○ Retrieve and verify the constructed object.


int main()
{
  
    SportsCarBuilder* sportCar = new SportsCarBuilder();
    SUVBuilder* suv = new SUVBuilder();

    Director* dicObj = new Director();
    dicObj->setBuilder(sportCar);
    dicObj->constructSportsCar();
    Car* car = dicObj->getCar();

    return 0;
}

// Step 7. Extend and Optimize
// 		○ Add more builders for different product variations.
// 		○ Ensure the pattern works well with smart pointers to manage memory efficiently.
// 		○ If needed, make the Director reusable by allowing dynamic builder swapping.