
/* private & protected inheritance: has-a relationship   */


#include<iostream>

class Engine
{
    protected:
    void startEngine()
    {
        std::cout << "engine started\n";
    }
};

class Car : private Engine
{
    public:
    void startCar()
    {
        startEngine();
    }
};


/// --- Abstract Class ---

class Vehicle
{
    public:
    virtual void start() = 0;
};

class Truck : public Vehicle
{
    public:
    void start() override
    {
        std::cout << "Truck started\n";
    }
};

// -- MAIN --

int main()
{
 Car c1;
 c1.startCar();

 Truck t1;
 t1.start();

 std::cout << std::endl;

 return 0;
}