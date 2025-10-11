/* passing arrays to a function*/

#include<iostream>

void centimize(double*, int);

int main()
{

 double v[] = {10.0, 20.0, 30.0, 40.0, 50.0};
 
 double* ptr;
 ptr = v;


 
 int len = sizeof(v)/sizeof(double);

 centimize(ptr, len);

 //--print
 for(int y=0;y<5;y++)
 {
    std::cout<<v[y]<<" ";
 }

std::cout<<std::endl;
return 0;
}


void centimize(double* arr, int len)
{

  
  for(int x=0; x<len; x++)
  {
    //arr[x]+=10;
    *(arr+x)+=10;
  }

}