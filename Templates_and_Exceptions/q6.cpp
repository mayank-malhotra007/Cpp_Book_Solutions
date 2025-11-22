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
            std::cout << "out of bounds!" << std::endl;
            return dummy;
        }
        return arr[s];
    }
};

// -- MAIN --
int main()
{
    const int SIZE = 3;
    Safe<int> s1;

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
    s1[5] = 100;  // will print "out of bounds!" safely

    return 0;
}

