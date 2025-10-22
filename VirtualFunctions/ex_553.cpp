/*  
    Dynamic Casting,
    RTTI - run time type information needs to be enabled, 
    Check the type of object,
    Change the type of object during runtime,
    Needs virtual function in base class, needs late binding
*/

#include<iostream>
#include<typeinfo>

class Base
{

  virtual void vertFunc(){}

};

class Derv1 : public Base
{};

class Derv2 : public Base
{};


bool isDerv1(Base* dd)
{
    auto x =dynamic_cast<Derv1*>(dd); // checks if dd points to Derv1 or not
    if(x) return true;
    else return false;
}

int main()
{
  
  Derv1* d1 = new Derv1;
  Derv2* d2 = new Derv2;

  if(isDerv1(d1)) std::cout << "d1 is a member of derv1" <<std::endl;

  std::cout << typeid(d1).name() <<std::endl;
  std::cout << typeid(d2).name() <<std::endl;

 return 0;
}
