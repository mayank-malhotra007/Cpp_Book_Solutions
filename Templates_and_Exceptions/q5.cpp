
#include<iostream>

template<typename T>
T findMax(T arr[], int size)
{
    T max = arr[0];
    for(int x=1; x<size; x++)
    {
        if(max<arr[x])
        {
            max = arr[x];
        }
    }

    return max;

}


// -- MAIN --
int main()
{
 const int SIZE = 5;
 
 int    int_arr[SIZE]    = {1,100,300,10,34};
 float  fl_arr[SIZE]     = {1.2, 100.23, 200.34, 0.11, 4.5};
 double double_arr[SIZE] = {10000, 2000, 100, 30000, 700000};
 long   long_arr[SIZE]   = {1000L, 30000L, 25000L, 50000L, 420000L};

 auto a = findMax(int_arr, SIZE);
 auto b = findMax(fl_arr, SIZE);
 auto c = findMax(double_arr, SIZE);
 auto d = findMax(long_arr, SIZE);



 std::cout << "maximum values are: " << std::endl 
     << a << std::endl 
     << b << std::endl
     << c << std::endl
     << d << std::endl;
 return 0;
}
