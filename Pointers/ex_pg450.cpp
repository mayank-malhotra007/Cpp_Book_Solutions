/* max and min from an array */

#include<iostream>

int max(int* , int);
int min(int* , int);


//-- MAIN --
int main()
{
 int num[]={10,20,30,100,70,60,1000,0};
 int* ptr = num;
 int len = sizeof(num)/sizeof(int);

 int max_element=max(ptr,len);
 std::cout<<"max: "<<max_element;   

 std::cout<<std::endl;
 int min_element = min(ptr,len);
 std::cout<<"min: "<<min_element;

 std::cout<<std::endl;
 return 0;
}


//-- MAX --
int max(int* p, int len)
{
  int max = 0;
  for(int x=0; x<len; x++)
  {
    if(*(p+x)>max)
    {
        max=*(p+x);
    }
  }
 
 return max;
}


//-- MIN --
int min(int* p, int len )
{
   int min=99999;

   for(int x=0; x<len; x++)
  {
    if(*(p+x)<min)
    {
        min=*(p+x);
    }
  }
     

    return min;
}