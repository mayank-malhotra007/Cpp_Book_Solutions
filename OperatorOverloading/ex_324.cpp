
#include<iostream>

class Counter
{
    int count;
    public:
    Counter(): count(0) {}

    int get_count()
    {
        return count;
    }

    //overload op++ but return a class object
    Counter operator++()
    {
        ++count;
        return *this;
        
        /*
        Counter temp;
        temp.count = count;
        return temp;
        */
    }

};


int main()
{
 Counter c1;

 std::cout << c1.get_count() << std::endl;

 Counter c2 =++c1;

 std::cout << c1.get_count() << std::endl;
 std::cout << c2.get_count() << std::endl;


 return 0;
}


