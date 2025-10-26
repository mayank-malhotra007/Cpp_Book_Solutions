#include<iostream>
#include<cmath>

class bMoney
{
    long double money;
    long double intpart;
    long double fracpart;

    public:

    bMoney(long double ll): money(ll){};
    
    long double getValue();
   


};

long double bMoney :: getValue()
{   
    fracpart = modfl(money, &intpart);
    std::cout << "fracpart: " << fracpart << std::endl;
    std::cout << "intpart:"  << intpart << std::endl;

    if(fracpart<0.50)
    {
        return intpart;
    }
    else
    {
        return intpart+1;
    }
}

int main()
{
 bMoney b1(10.25);
 bMoney b2(20.78);
 bMoney b3(5.50);

 long double result = 0;

 result=b1.getValue();
 std::cout << "result: " << result <<std::endl;
 
 result=b2.getValue();
 std::cout << "result: " << result <<std::endl;

 result=b3.getValue();
 std::cout << "result: " << result <<std::endl;

 return 0;
}