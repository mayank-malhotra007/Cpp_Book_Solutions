/*
a simple function template
-> templates can be function template or class templates and are used for general purpose programming
*/

#include<iostream>


template<typename T>
T abs(T n)
{
    return (n<0 ? -n : n);
}


int main()
{
 int int1 = 5;
 int int2 = -6;
 long l1 = 17000L;
 long l2 = -18000L;

 double d1 = 9.95;
 double d2 = -10.15;

 std::cout << abs(int1) << std::endl;
 std::cout << abs(int2) << std::endl;
 std::cout << abs(l1)  << std::endl;
 std::cout << abs(l2) << std::endl;
 std::cout << abs(d1) << std::endl;
 std::cout << abs(d2) << std::endl;



 return 0;
}