
#include<iostream>

class Counter
{
    int count;

    public:
    Counter(): count(0){}
    Counter(int d): count(d){}

    int get_count()
    {
        return count;
    }

    // return a class object but using constructor
    Counter operator ++ ()
    {
        ++count;
        return Counter(count);
    }

};


// --- MAIN ---
int main()
{
 Counter c1;

 std::cout << c1.get_count() << std::endl;

 Counter c2 = ++c1;


 std::cout << c1.get_count() << std::endl;
 std::cout << c2.get_count() << std::endl;


 return 0;
}

