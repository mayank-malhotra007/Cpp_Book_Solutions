/*
    counten2.cpp
*/

#include<iostream>

class Counter
{
    protected:
    unsigned int count;

    public:
    Counter(): count(0) {}

    Counter(int c): count (c) {}

    unsigned int get_count()
    {
        return count;
    }

    Counter operator++ ()
    {
        return Counter(++count);
    }

};

class CountDn : public Counter
{
    public:
    CountDn():Counter() {}

    // invoke a constructor from a constructor
    CountDn(int c): Counter(c) {}

    CountDn operator-- ()
    {
        return CountDn(--count);
    }

};

// --- MAIN ---

int main()
{
 CountDn d1(10);

 std::cout << d1.get_count() << std::endl;

 ++d1;
 ++d1;
 
 std::cout << d1.get_count() << std::endl;

 --d1;
 std::cout << d1.get_count() << std::endl;

 
 return 0;
}