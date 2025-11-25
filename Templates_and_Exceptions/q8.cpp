#include <iostream>

template<typename T>
class Safe
{
    static const int size = 3;
    T arr[size];

public:
    T& operator[](int s)
    {
        static T dummy{};
        if(s < 0 || s >= size)
        {
            
            throw s;
            
        }
        return arr[s];
    }
};

// -- MAIN --
int main()
{
    const int SIZE = 3;

    Safe<float> s1;
   
    
    for(int i = 0; i < SIZE; i++)
    {
        s1[i] = i * 2;
    }

    // display
    for(int j = 0; j < SIZE; j++)
    {
        std::cout << s1[j] << " ";
    }

    std::cout << std::endl;

    // test out-of-bounds
    try{
        s1[5] = 100;  
    }
    catch(int& index)
    {
        std::cout <<"problematic index:" << index << std::endl;
    }


    return 0;
}


