// Counten2.cpp extended

#include<iostream>

class Count
{
    int count;

    public:
    Count() : count(0) {}
    
    int get_count()
    {
        return count;
    }
    
    //prefix
    void operator++()
    {
        count+=1;
        
    }


    //postfix
    int operator++(int)
    {
        int temp = count;
        count++;
        return temp;
    }

     //prefix
    void operator--()
    {
        count-=1;
        
    }


    //postfix
    int operator--(int)
    {
        int temp = count;
        count--;
        return temp;
    }


};


class CountUpDw : public Count
{

    public:
    CountUpDw() : Count() {}


};



// ----- MAIN ----
int main()
{
 CountUpDw d1;

 std::cout << d1.get_count() << std::endl; 

 ++d1;
 std::cout << d1.get_count() << std::endl; 

 int x = d1++;
 std::cout << x << std::endl; 

 std::cout << d1.get_count() << std::endl; 

 --d1;
 std::cout << d1.get_count() << std::endl; 

 int y = d1--;
 std::cout << y << std::endl; 



 return 0;
}