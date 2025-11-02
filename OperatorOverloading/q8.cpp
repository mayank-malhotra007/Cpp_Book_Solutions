#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include<sstream>

/*
 use ostringstream to format a string like using setprecision()
 use istringstream to convert/parse a string to a number
 use stringstream for both

*/


class bMoney {
    long double money;

public:
    bMoney() : money(0.0L) {}
    bMoney(long double m) : money(m) {}

    void getmoney() {
        std::cout << "Enter money: ";
        std::cin >> money;
    }

    //display numeric
    void display() const {
        std::cout << std::fixed << std::setprecision(2) << money << std::endl;
    }

    //display as string
    void display_string()
    {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << money;
        std::string s =oss.str(); //fetch the string from oss 

        std::cout << s << std::endl;
    }

    // Arithmetic operators
    bMoney operator+(const bMoney& rhs) const {
        return bMoney(money + rhs.money);
    }

    bMoney operator-(const bMoney& rhs) const {
        return bMoney(std::abs(money - rhs.money));
    }

    bMoney operator*(long double rhs) const {
        return bMoney(money * rhs);
    }

    bMoney operator/(long double rhs) const {
        if(rhs == 0.0L) {
            std::cerr << "Divide by 0 error" << std::endl;
            exit(1);
        }
        return bMoney(money / rhs);
    }

    long double operator/(const bMoney& rhs) const {
        if(rhs.money == 0.0L) {
            std::cerr << "Divide by 0 error" << std::endl;
            exit(1);
        }
        return money / rhs.money;
    }
};


int main() { 
    bMoney b1; 
    b1.getmoney(); 
    b1.display(); 
    

    bMoney b2; 
    b2.getmoney(); 
    b2.display(); 

    bMoney b3 = b1 + b2; 
    b3.display();
    b3.display_string(); 

    bMoney b4 = b1 - b2; 
    b4.display(); 
    b4.display_string();

    bMoney b5 = b1 * 100; 
    b5.display(); 
    b5.display_string();

    bMoney b6 = b1 / 100; 
    b6.display(); 
    b6.display_string();

    long double b7 = b1 / b2; 
    std::cout << b7 << std::endl; 
    return 0; 
}