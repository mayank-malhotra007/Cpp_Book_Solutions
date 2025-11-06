/*
 counten.cpp
*/

#include<iostream>

class Counter
{
    protected:
    unsigned int count;

    public:
    
    Counter(): count(0) {}

    Counter(int c): count(c) {}

    unsigned int get_count()
    {
        return count;
    }

    Counter operator++ ()
    {
        return Counter(++count);
    }
};

// protected member of class Counter stay protected in class CountDn

class CountDn: public Counter
{

    public:
    Counter operator-- ()
    {
        return Counter(--count);
    }
};

// --- MAIN ---

int main()
{
 CountDn c1;
 

 std::cout << c1.get_count() << std::endl;

 ++c1;
 ++c1;
 ++c1;

 std::cout << c1.get_count() << std::endl;

 //c1.count = 5;
 
 --c1; --c1; --c1;
 std::cout << c1.get_count() << std::endl;


 return 0;
}