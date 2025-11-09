/*
 using scope resolution to resolve ambiguity
*/

#include<iostream>

class A
{
    public:
    void show()
    {
        std::cout << "A"<< std::endl;
    }

};

class B
{
    public:
    void show()
    {
        std::cout << "B" << std::endl;
    }
};

class C : public A, public B
{

};


int main()
{
  C objc;
  //objc.show(); // ambiguity


  objc.A::show();
  objc.B::show();

  return 0;
}

