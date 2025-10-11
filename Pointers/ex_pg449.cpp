/* sort an array */

#include<iostream>

void sort(int* , int len);

//-- MAIN --
int main()
{
 int v[]={20,10,30,60,100,33};
 int len = sizeof(v)/sizeof(int);

 sort(v, len);
 
 for(int i=0; i<len; i++)
 {
    std::cout<<v[i]<<" ";
 }
 return 0;
}



//--sort algo---
void sort(int* v, int len)
{
 int max=0;
 for(int i=0; i<len-1; i++)
 {
    for(int j=i+1; j<len; j++)
    {
        //asc order
       if(v[i]>v[j])
       {
          int temp;
          temp = *(v+i);
          *(v+i)=*(v+j);
          *(v+j)=temp;
       }
    }
 }
}
