
#include<iostream>

template<typename atype>
int find(atype* array, atype value, int size)
{
    for(int x=0; x<size; x++)
    {
        if(array[x] == value)
        {
            return x;
        }
    }

    return -1;
}

// -- MAIN --
int main()
{
 int num[5]     = {1,2,3,4,5};
 long num2[3]   = {17000L, 18000L};
 double num3[2] = {14.4, 15.6};

 std::cout << "index: " << find(num, 3, 5) << std::endl;
 std::cout << "index: " <<find(num2, 17000L, 2) << std::endl;
 std::cout << "index: " <<find(num3, 14.4, 2) << std::endl;

 return 0;
}