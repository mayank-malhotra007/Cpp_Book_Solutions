/*
    safearray
*/

#include<iostream>

const int LOWER = 0;
const int UPPER = 50;
const int size = 50;

class safeArray
{

    int arr[size];

    public:

    // setter & getter
    int& operator[] (int n)
    {
        if(n < LOWER || n >= UPPER)
        {
            std::cout << "out of bounds" << std::endl;
            return arr[0];
        }
        else
        {
            return arr[n];
        }
    }

  

};

//  [] here returns an address of the nth element.

int main()
{
    safeArray a1;

    // fill in the array
    for(int i=0; i<10; i++)
    {
        a1[i] = i+10;
    
    }


    int x = a1[5];
    std::cout << x << std::endl;


 return 0;
}