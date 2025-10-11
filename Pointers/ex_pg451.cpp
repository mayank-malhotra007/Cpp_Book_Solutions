/* reverse the array */

#include<iostream>

void reverse(int*, int*, int);
void reversal(int*, int);


//-- MAIN --
int main()
{
 int numbers[] = {10,20,30,40,50};
 int len = sizeof(numbers)/sizeof(int);
 int* start = numbers;
 int* end = (numbers+len-1);

 reverse(start, end, len);


 std::cout<<"first reversal"<<std::endl;
 for(int i:numbers)
 {
    std::cout<<i<<" ";
 }

 reversal(numbers,len);
 std::cout<<std::endl;
 std::cout<<"second reversal"<<std::endl;
 for(int i:numbers)
 {
    std::cout<<i<<" ";
 }
 
 return 0;
}


//-- Reverse Function --
void reverse(int* start, int* end, int len)
{
   while(start<end)
   {
    int temp;
    temp=*start;
    *start=*end;
    *end = temp;

    start++;
    end--;
   }
}


//-- Reversal --
void reversal(int* arr,int len)
{
  int start = 0;
  int end = len-1;
  
  //iterate till midpoint only
  for(int x=start; x<len/2; x++)
  {
     int temp;
     temp = *(arr+x);
     *(arr+x) = *(arr+end);
     *(arr+end) = temp;
     end--;
  }
}