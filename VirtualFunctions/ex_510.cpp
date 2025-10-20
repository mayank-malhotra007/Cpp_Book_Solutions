/*
 Abstract classes serves as a blueprint or a template for derived classes, it cannot be instantiated, no obejcts can
 be created for an abstract class.
 It needs one or more pure virtual functions.

*/

#include<iostream>

class Base 
{
    public:
    // pure virtual function
    virtual void show() = 0;
    
};

class Derv1 : public Base
{
    public:
    void show()
    {
        std::cout << "derv1" << std::endl;
    }

};


class Derv2 : public Base
{

    public:
    void show()
    {
        std::cout << "derv2" << std::endl;
    }
};


// --- MAIN ---
int main()
{
    //Base b;  cant make an object of abstract class

    Base* arr[2];
    Derv1 d1;
    Derv2 d2;
    
    // Note: pointer type is Base but object type is derived

    arr[0] = &d1;
    arr[1] = &d2;

    for(int x =0; x<2; x++)
    {
        arr[x]->show();
    }

 return 0;
}
