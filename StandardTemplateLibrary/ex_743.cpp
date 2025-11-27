
#include<iostream>
#include<algorithm>
#include<iomanip>

// -- MAIN --
int main()
{ 
 double inches[] = {1.2, 2.5, 39, 4.5, 5.5};
 double centi[5];

 double in_to_cm(double);

 std::transform(inches, inches+5, centi, in_to_cm);

 // -- print
 for(int x=0; x<5; x++)
 {
    std::cout <<std::fixed << std::setprecision(2) 
    << centi[x] << std::endl;
 }

 return 0;
}


double in_to_cm(double in)
{
    return in*2.54;
}