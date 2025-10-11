
#include<iostream>

// pass by reference
void centimeter(double&);

// pass by value
int decimeter(int);

// pass by pointer
void millimeter(float*);


int main()
{
 double var = 10.0;
 float f = 30.1;
 std::cout<<var<<std::endl;
 centimeter(var);
 std::cout<<var<<std::endl;

 int var2 = decimeter(var);
 std::cout<<var2<<std::endl;

 float* fptr;
 fptr=&f;
 
 std::cout<<"float: "<<*fptr<<std::endl;
 millimeter(fptr);
 std::cout<<"new float: "<<*fptr<<std::endl;
 
 std::cout<<std::endl;
 return 0;
}


void centimeter(double& x)
{
 x*=2.54;

}


int decimeter(int x)
{
 x+=10;
 return x;


}


void millimeter(float* fp)
{
 *fp+=100;
}