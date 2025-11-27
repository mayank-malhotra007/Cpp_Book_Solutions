
#include<iostream>
#include<algorithm>

void in_to_cm(double);

int main()
{
 double inches[] = {1.2, 6.2, 3.5};
 
 std::for_each(inches, inches+3, in_to_cm);

 std::cout << std::endl;

 return 0;
}

void in_to_cm(double in)
{
    double cm;
    cm = in*2.5;
    std::cout << cm << std::endl;
    
}
