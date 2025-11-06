/*
 An example of composition, loose coupling, no inheritance
*/

#include<iostream>

class Engine
{
 public:
 void start()
 {
    std::cout << "engine started\n";
 }

};

// this is a composition, car has an engine
class Car
{
    private:
    Engine engine;

    public:
    void startCar()
    {
        engine.start();
        std::cout << "car is running\n";
    }

};

int main()
{
  Car c;
  c.startCar();

 return 0;
}