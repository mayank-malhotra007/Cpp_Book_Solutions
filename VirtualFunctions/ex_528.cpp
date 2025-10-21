
#include<iostream>



class alpha
{
    int data1;

    public:
        alpha(): data1(9){}
        friend class beta;

};

class beta
{

    public:
     void func1(alpha a)
     {
        std::cout << a.data1 << std::endl;
     }  
     void func2(alpha a)
     {
        std::cout << a.data1 << std::endl;
     }
};

int main()
 {
    alpha a;
    beta b;

    b.func1(a);
    b.func2(a);

    std::cout << std::endl;
    return 0;
 }