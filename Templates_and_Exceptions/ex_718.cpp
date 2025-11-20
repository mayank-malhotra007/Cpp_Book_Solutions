/*
 Badalloc
*/

#include<iostream>

int main()
{
 const unsigned long SIZE = 100000000;
 char* ptr;

 try
 {
    ptr = new char[SIZE];

 }catch(std::bad_alloc& e)
 {
    std::cout << "bad memory allocation" << std::endl;
    return -1;
 }

 delete ptr;
 
 return 0;
}