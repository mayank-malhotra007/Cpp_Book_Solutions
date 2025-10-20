/*
 Virtual functions enable runtime polymorphism, allowing the correct function to be called depending upon the 
 object type not on the pointer type.
 Virtual function is a member function in base class, that the user shall override in derived classes(s). 
 They are needed as they enable runtime polymorphism.
 This is late binding, at runtime, not compile time which is static binding.

*/

#include<iostream>

class Shape
{
    public:
    virtual void show()
    {
        std::cout << "this is a shape class" << std::endl;
    }

    ~Shape()
    {
        std::cout << "base destructor called" << std::endl;
    }
};


class Sqaure : public Shape
{
    public:
    void show()
    {
        std::cout << "this is square class" << std::endl;
    }
};


class Triangle : public Shape
{
    public:
    void show()
    {
        std::cout << "this is triangle class" << std::endl;
    }
};




int main()
{
 Shape* ptr1 =new Sqaure();
 Shape* ptr2= new Triangle();

 ptr1->show();
 ptr2->show();

 return 0;
}