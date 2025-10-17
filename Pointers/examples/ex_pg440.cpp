
#include<iostream>

int main()
{
 int arr[] = {1,2,3,4,5};
 int* ptrArr; //pointer to an array of ints
 ptrArr = arr;

 int len = sizeof(arr)/sizeof(int);
 
 for(int x=0; x<len; x++)
 {
    std::cout<<(ptrArr+x)<<":"<<*(ptrArr+x);
    std::cout<<std::endl;
 }

 //---- constant ptr VS pointer to a const -----
 
 //case1 pointer to a const int {can point to any varibale of same type but cant modify the value}
 const int a = 10;
 const int* ptr1;
 ptr1=&a;

 //*ptr1=20;

 //case2 const pointer to a type {points to a single addr in memory, but can modify the value}
 int b = 20;
 int* const ptr2=&b;

 *ptr2=30;

 int c = 40;
 //ptr2=&c;


 return 0;
}