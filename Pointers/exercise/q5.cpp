
#include<iostream>
#include<string>

void sum_arr(int*, int*, int*, int);

// --- MAIN ---
int main()
{
 const int size = 5;
 
 int one[size] = {1,2,3,4,5};
 int two[size] = {1,2,3,4,5};
 int three[size];

 int* ptr1=one;
 int* ptr2=two;
 int* ptr3=three;

 sum_arr(ptr1,ptr2,ptr3,size);

 // display the third array
 for(int x=0; x<size; x++)
 {
    std::cout<<*(ptr3+x)<<" ";
 }

 std::cout<<std::endl;
 return 0;
}


// -- sum of arrays --
void sum_arr(int* p1, int* p2, int* p3, int len)
{
  for(int x=0; x<len; x++)
  {
    *(p3+x) = (*(p1+x) + *(p2+x));
  }
}
