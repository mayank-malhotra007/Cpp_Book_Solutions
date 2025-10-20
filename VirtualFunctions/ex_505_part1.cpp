
/* Static binding, the compiler decides which function to call depending upon the return type of pointer, not its contents */
/* When virtual keyword is used, the compiler looks at the object or type pointer to by the pointer instead */


#include<iostream>

class Base
{
    public:
    void show()
    {
        std::cout << "base" << std::endl;
    }
};

class Derv1 : public Base
{
    public:
    void show()
    {
        std::cout << "derived 1" << std::endl;
    }
};

class Derv2 : public Base
{
    public:
    void show()
    {
        std::cout << "derived 2" << std::endl;
    }
};

int main()
{
 Derv1 d1;
 Derv2 d2;
 Base* ptr;

 ptr = &d1;
 ptr->show();

 ptr = &d2;
 ptr->show();

 return 0;
}