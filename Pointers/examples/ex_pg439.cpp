#include<iostream>

int main() {

    int intvar = 10;
    float floatvar = 20.01;

    int* ptrint;
    float* ptrflo;
    //void pointer
    void* ptrvoid;

    ptrint = &intvar;
    ptrflo = &floatvar;
    ptrvoid = &ptrint;

    std::cout<<ptrint<<" "<<ptrflo<<" "<<ptrvoid;
    std::cout<<std::endl;

    ptrvoid = &floatvar;
 
    std::cout<<ptrint<<" "<<ptrflo<<" "<<ptrvoid;
    std::cout<<std::endl;

    //cannot dereference a void pointer
    //std::cout<<*ptrvoid 

    //typecast the void pointer to access it
    float* vptr = (float*)ptrvoid;
    std::cout<<*vptr;

    return 0;
}