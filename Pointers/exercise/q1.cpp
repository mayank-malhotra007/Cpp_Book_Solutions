
#include<iostream>

const int size = 5;

int calculate_avg(int*, int );

int main()
{
    int numbers[size];
    
    for(int x=0; x<size; x++)
    {
        std::cout<<"enter number: ";
        std::cin>>numbers[x];
    }
 
    int result=0;
    result=calculate_avg(numbers,size);

    std::cout<<"avg is: "<<result<<std::endl;

 return 0;
}



int calculate_avg(int* p, int len)
{
    static int sum=0;
    for(int x=0;x<len; x++)
    {
        sum+= *(p+x);
    }

    std::cout<<"sum is: "<<sum<<std::endl;
    int avg =0;
    avg = sum/len;
    

    return avg;
}