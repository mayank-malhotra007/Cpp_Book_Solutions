
#include<iostream>

class Counter
{
    static int count;

    public:
    

    static int get_count()
    {
        return count;
    }

    //overload ++ op
    void operator ++()
    {
        count+=5;
    }

};

// we have to define static variables, else the linker wont know where to find it.
int Counter::count=0;

int main()
{
 Counter c1, c2;
 std::cout << c1.get_count() << std::endl;
 std::cout << c2.get_count() << std::endl;

 ++c1;


 std::cout << c1.get_count() << std::endl;
 std::cout << c2.get_count() << std::endl;


 return 0;
}