
/* overload the [] operator */
/* arrover3.cpp */

#include<iostream>
const int LIMIT = 10;

class safearray
{
 int arr[LIMIT];

 public:
 
 void getdata(int x, int value)
 {
    arr[x]=value;
 }

 int& operator[](int index)
 {
    return arr[index];
 }


};



// -- MAIN --
int main()
{
 safearray s1;

 // fills the array
 for(int i=0; i<LIMIT; i++)
 {
    s1.getdata(i,i);
 }
 
 //loop and invoke [] operator
 for(int x=0; x<LIMIT; x++)
 {
    std::cout << s1[x] << std::endl;
 }


 return 0;
}

