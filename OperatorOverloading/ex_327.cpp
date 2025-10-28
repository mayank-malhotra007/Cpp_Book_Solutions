
/*
    Postfix notation
*/

#include<iostream>

class Counter
{
    unsigned int count;

    public:
    Counter():count(0){}
    Counter(unsigned int d): count(d) {}

    unsigned int get_count()
    {
        return count;
    }

    //prefix
    Counter& operator++()
    {
        ++count;
        return *this;
    }

    //postfix
    Counter operator++(int)
    {
        Counter temp = *this; // copy old value of c1
        ++count;
        return temp;
    }

};



int main()
{
  Counter c1;
  std::cout <<"c1: " << c1.get_count() << std::endl;

  Counter c2 = ++c1;
  std::cout <<"c1: " << c1.get_count() << std::endl;
  std::cout <<"c2: " << c2.get_count() << std::endl;

  Counter c3 = c1++;
  std::cout <<"c1: " << c1.get_count() << std::endl;
  std::cout <<"c3: " << c3.get_count() << std::endl;
  
  c3 = c1++;
  std::cout <<"c1: " << c1.get_count() << std::endl;
  std::cout <<"c3: " << c3.get_count() << std::endl;




 return 0;
}