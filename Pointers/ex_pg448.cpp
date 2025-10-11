/* swap using pointers */

#include<iostream>

void swap(int* , int*);

int main()
{
 int a=10;
 int b=20;
 
 int* ptr1 = &a;
 int* ptr2 = &b;

 std::cout<<*ptr1<<" "<<*ptr2;
 swap(ptr1,ptr2);
 std::cout<<std::endl;
 std::cout<<*ptr1<<" "<<*ptr2;


 return 0;
}

void swap(int* p1, int* p2)
{
  int temp;
  temp = *p1;
  *p1=*p2;
  *p2=temp;
}