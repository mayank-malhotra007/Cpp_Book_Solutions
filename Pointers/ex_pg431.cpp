#include<iostream>

int main()
{
    int var1 = 11;
    int var2 = 22;
    int var3 = 33;

    std::cout<<&var1<<" "<<&var2<<" "<<&var3;

    int* ptr1 = &var1;
    int* ptr2 = &var2;
    int* ptr3 = &var3;

    std::cout<<std::endl;
    std::cout<<ptr1<<" "<<ptr2<<" "<<ptr3;
    std::cout<<std::endl;
    std::cout<<*ptr1<<" "<<*ptr2<<" "<<*ptr3;

    std::cout<<std::endl;
    return 0;
}