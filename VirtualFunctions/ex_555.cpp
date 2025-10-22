/* 
 change pointer type using Dynamic Cast,
 a derived object can by casted into base,
 a base cannot unless a base ptr is created that points to the derived object
*/

#include<iostream>
#include<typeinfo>

class Base
{
    protected:
     int ba;

    public:
     Base() : ba(0) {}

     Base(int b): ba(b) {}

     virtual void vertFunc(){}

     virtual void show()
     {
        std::cout << "base: ba =" << ba << std::endl;
     }

};


class Derv : public Base
{
    int da;

    public:
        Derv(int b, int d): da(d)
        { ba = b;}

        void show()
        {
            std::cout << "ba: " << ba << "da: " << da << std::endl;
        }
};


int main()
{
 Base* pBase = new Base(10);
 Derv* pDerv = new Derv(31,21);

 pBase -> show();
 pDerv -> show();

 //cast a derive class object into base class
 //pBase = dynamic_cast<Base*>(pDerv);
 //pBase -> show();

 // same as above
 pBase = new Derv(100,200);
 pBase->show();

 // base to derive
 pDerv = dynamic_cast<Derv*>(pBase);
 pDerv -> show();

 return 0;
}