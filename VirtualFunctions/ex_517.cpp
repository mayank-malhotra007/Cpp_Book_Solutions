
#include<iostream>

class Base
{
    public:
        // due to this virtual dest, both derv and base dest are called
        virtual ~Base()
        {
            std::cout << "base destructor" << std::endl;
        }
};


class Derv : public Base
{
    public:
    ~Derv()
    {
        std::cout << "derv destructor" << std::endl;
    }

};

int main()
{
 Base* ptr = new Derv();

 delete ptr;

 return 0;
}