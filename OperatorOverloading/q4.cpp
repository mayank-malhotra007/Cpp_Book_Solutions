/*
 employee
*/

#include<iostream>

class Int
{
    long double value;
    

    public:
    Int(): value(0) {}

    Int(long double x): value(x) {}

    Int operator+ (const Int& rhs)
    {
        long double sum = value + rhs.value;
        return Int(sum);
    }

    Int operator- (const Int& rhs)
    {
        long double diff;
        if(value>rhs.value)
        {
            diff = value-rhs.value;
        }else {
            diff = rhs.value - value;
        }

        return Int(diff);
    }


    Int operator* (const Int& rhs)
    {
        long double mult;

        mult = value * rhs.value;
        return Int(mult);
    }

    Int operator/ (const Int& rhs)
    {
        if(rhs.value == 0)
        {
            std::cerr << "division by zero" << std::endl;
            return -1;
        }
        else
        {
            long double div;
            div = value / rhs.value;
            return Int(div);
        }
    }



    void display() const
    {
        std::cout << value << std::endl;
    }
   
    long double getValue()
    {
        return value;
    }
};




int main()
{
    
  Int i1(10);
  Int i2(20);

  i1.display();
  i2.display();

  Int i3;
  
  char ch;
  std::cout << "enter choice [+,-,*,/]";
  std::cin >> ch;

  switch(ch)
  {
    case '+': i3 = i1 + i2; break;
    case '-': i3 = i1 - i2; break;
    case '*': i3 = i1 * i2; break;
    case '/': i3 = i1 / i2; break;
  }
  
  i3.display();

  if(i3.getValue()>2147483648 && i3.getValue()<-2147483647)
  {
    std::cerr << "out of INT range" << std::endl;
  }

  return 0;
}