/* 
  Operator Overloading  ! Important Program !
  member functions will take one arg, the rhs of operator,
  friend functions will take 2 args, lhs and rhs of the operator
*/

#include<iostream>
#include<format>
#include<string>
#include<iomanip>
#include<sstream>

class bMoney
{
    long double money;

    public:
    //constructros
    bMoney(){};

    bMoney(long double x, long double y) 
    {
        std::cout << "2 args constructor called" << std::endl;
        money = x+y;
    }

    bMoney(long double rhs)
    {
        std::cout << "1 arg constructor called" << std::endl;
        money = rhs;
    }

    // get  money
    void getmoney();
    
    // display
    void putmoney();
    
    //member functions
    bMoney operator*(const long double );
    long double operator/(const bMoney& ) const;
    bMoney operator/(const long double );


    //friend functions
    friend bMoney operator+(bMoney m1, bMoney m2);
    friend bMoney operator-(bMoney m1, bMoney m2);
    
    // new additions
    friend long double operator*(long double, bMoney);
    friend long double operator/(long double, bMoney);

};

long double string_to_longdouble(std::string );

void bMoney :: getmoney()
{
    std::string s;
    std::cout<< "enter money as a string: ";
    std::cin>>s;
    long double y=string_to_longdouble(s);
    money = y;
}

// coverts money as a string to long double
long double string_to_longdouble(std::string s)
{
    long double x = std::stold(s);
    return x;
}

// converts long double to string
void bMoney :: putmoney()
{
    //std::string ss = std::to_string(money);
    //std::cout << "money entered is: "<< ss << std::endl;
    
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << money; // 18 digits precision
    std::string s = oss.str();
    std::cout << "money is: "<< s << std::endl;
}


bMoney operator+(bMoney m1, bMoney m2)
{
    return bMoney(m1.money + m2.money,0);
    
}

bMoney operator-(bMoney m1, bMoney m2)
{
    return bMoney(m1.money - m2.money, 0);
    
}


bMoney bMoney::operator*(const long double rhs)
{
  std::cout<<"money: " << money << std::endl;
  std::cout << "rhs: " << rhs << std::endl;
  return bMoney(money*rhs);
}


long double bMoney::operator/(const bMoney& rhs) const
{
   if (rhs.money == 0)
   {
       std::cerr << "Error: division by zero\n";
       return 0.0L;
   }
   return money / rhs.money;
}


 bMoney bMoney :: operator/(const long double rhs)
 {
    if(rhs == 0)
    {
        std::cerr << "divide by zero" << std::endl;
    }

    return bMoney(money/rhs);
    
 }


long double operator*(long double ll, bMoney rhs)
{
  return (ll * rhs.money);
}

long double operator/(long double ll, bMoney rhs)
{
    if(rhs.money == 0)
    {
        std::cerr << "division by zero" << std::endl;
    }

    return (ll / rhs.money);
}

// --- MAIN ---
int main()
{
 bMoney b1;
 b1.getmoney();
 b1.putmoney();

 bMoney b2;
 b2.getmoney();
 b2.putmoney();

 bMoney b3 = b1 + b2;
 b3.putmoney();

 bMoney b4;
 b4 = b1 * 10.25;
 b4.putmoney();

 long double divide_result = b1/b2;
 std::cout <<"after division: " << divide_result << std::endl;

 bMoney b5;
 b5 = b1/10.00;
 b5.putmoney();

 long double x = 1000.00 / b1;
 std::cout << "x: " << x << std::endl;

 long double y =  20.0 * b1;
 std::cout << "y: " << y << std::endl;

 return 0;
}