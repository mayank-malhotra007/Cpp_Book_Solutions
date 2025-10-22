/*
 copy constructor,
 copy assignment
*/

#include<iostream>

class alpha
{
 int data;

 public:
    alpha(){}
    alpha(int d):data(d) {}

    //copy constuctor
    alpha(const alpha& rhs)
    {
        std::cout << "copy constructor called" << std::endl;
        data = rhs.data;
    }

    //copy assignment
    void operator=(const alpha& rhs)
    {
        std::cout << "copy assignment called" << std::endl;
        data = rhs.data;
    }

    // display
    friend void display(const alpha& rhs);

    // destructor
    ~alpha()
    {   
        std::cout << "destructor called" << std::endl;
    }


};


void display(const alpha& rhs)
{
    std::cout << rhs.data << std::endl;
}



// -- MAIN --
int main()
{
  alpha a1(10);
  alpha a2 = a1;
  alpha a3(a1);
  alpha a4;
  a4 = a1;

  display(a1);
  display(a2);
  display(a3);
  display(a4);



 return 0;
}