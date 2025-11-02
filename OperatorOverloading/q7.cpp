/*

Implement these using the overload operators

1/2 + 1/2 = 1
1/2 - 1/2 = 0
1/2 * 1/2 = 1/4
1/2 / 1/2 = 1

-> a/b + c/d = (a*d + b*c) / (bd)
-> a/b - c/d = (a*d - b*c) / (bd)
-> a/b * c/d = (a*c) / (b*d)
-> a/b / c/d = (a*d) / (b*c)

*/



#include<iostream>


class Fraction
{

    int a,b;

    public:
    Fraction():a(0), b(0) {}
    Fraction(int numer, int denom): a(numer), b(denom) {}

    void getfraction()
    {
        std::cout << "enter a: "; std::cin >> a;
        std::cout << "enter b: "; std::cin >> b;
        
    }

    void displayfraction()
    {
       std::cout <<"Fraction is: "<< a << "/" << b << std::endl;
    }

    Fraction operator+ (const Fraction& rhs)
    {   
        int up =   (a*rhs.b + b*rhs.a) ;
        int down = (b*rhs.b) ;

        return Fraction(up,down);

    }

    Fraction operator- (const Fraction& rhs)
    {
        int up = (a*rhs.b - b*rhs.a);
        int down = (b*rhs.b);

        return Fraction(up,down);

    }

    Fraction operator* (const Fraction& rhs)
    {
        int up = a*rhs.a;
        int down = b*rhs.b;

        return Fraction(up,down);

    }

    Fraction operator/ (const Fraction& rhs)
    {
        int up, down;
        if(rhs.a == 0) 
        {   
            std::cerr << "didvide by 0" << std::endl;
            exit(1);
            
        }
        else
        {
            up = a*rhs.b;
            down = b*rhs.a;
        }

        return Fraction(up,down);

    }

    bool operator==(const Fraction& rhs)
    {
        int temp_1 = a / b;
        int temp_2 = rhs.a / rhs.b;

        if(temp_1 == temp_2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool operator!=(const Fraction& rhs)
    {
        int temp_1 = a / b;
        int temp_2 = rhs.a / rhs.b;

        if(temp_1 != temp_2)
        {
            return true;
        }
        else
        {
            return false;
        }

    }

};



// -- MAIN --
int main()
{
 Fraction f1,f2;
 f1.getfraction();
 f2.getfraction();

  Fraction added = f1 + f2;
  std::cout << "Added ";
  added.displayfraction();

  Fraction sub = f1 - f2;
  std::cout << "Sub ";
  sub.displayfraction();

  Fraction mult = f1 * f2;
  std::cout << "Mult ";
  mult.displayfraction();

  Fraction div = f1 / f2;
  std::cout << "Divide ";
  div.displayfraction();

 bool report_equal = (f1 == f2);
 bool report_notEqual = (f1 != f2);

 std::cout << "report_equal: "    <<(report_equal ? "true": "false") << std::endl;
 std::cout << "report_notEqual: " <<(report_notEqual ? "true": "false") << std::endl;
 
 return 0;
}


