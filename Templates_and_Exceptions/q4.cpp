
/* Swap Funtion */
#include<iostream>


template<typename T>
void swap(T& x, T& y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
    
}


int main()
{
 int a = 5; int b = 10;
 float m = 10.67; float n = 20.33;
 long x = 10000L; long y = 2000L;


 std::cout << a << "," << b << std::endl;
 swap(a,b);
 std::cout << a << "," << b << std::endl;
 
 
 std::cout << m << "," << n << std::endl;
 swap(m,n);
 std::cout << m << "," << n << std::endl;
 
 
 std::cout << x << "," << y << std::endl;
 swap(x,y);
 std::cout << x << "," << y << std::endl;


 return 0;
}


