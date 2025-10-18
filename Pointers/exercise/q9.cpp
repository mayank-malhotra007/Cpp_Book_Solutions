/*    2D array    */

#include<iostream>

int main()
{
    const int size = 10;

    int a0[]={1,2,3,4,5};
    int a1[]={6,7,8,9,10};
    int a2[]={11,12,13,14,15};
    int a3[]={16,17,18,19,20};
    int a4[]={21,22,23,24,25};
    int a5[]={26,27,28,29,30};
    int a6[]={31,32,33,34,35};
    int a7[]={36,37,38,39,40};
    int a8[]={41,42,43,44,45};
    int a9[]={46,47,48,49,50};

    int* ptr_array[size] = {a0,a1,a2,a3,a4,a5,a6,a7,a8,a9};

    /*
    for(int x=0; x<size; x++)
    {
        std::cout<<*(ptr_array+x)<<":"<<**(ptr_array+x)<<std::endl;
    }
    */

    for(int x=0; x<size; x++)
    {
        for(int y=0; y<5; y++)
        {
            std::cout<<ptr_array[x][y]<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}