// engmult.cpp
// multiple inheritance

#include<iostream>

class Type
{
    private:
    std::string dimension;
    std::string grade;

    public:
    Type() : dimension(""), grade("") {}
    Type(std::string d, std::string g): dimension(d), grade(g) {}

    void gettype()
    {
        std::cout << "enter dimension: "; std::cin >> dimension;
        std::cout << "enter grade: "; std::cin >> grade;

    }

    void putdata()
    {
        std::cout << dimension << std::endl
                  << grade << std::endl;
    }


};


class Distance
{
    int feet;
    float inches;

    public:
    Distance():feet(0), inches(0) {}
    Distance(int f, float i) : feet(f), inches(i) {}

    void getDistance()
    {
        std::cout << "enter feet: "; std::cin >> feet;
        std::cout << "enter inches: "; std::cin >> inches;
    }

    void showDistance()
    {
        std::cout << feet << " \' " << inches << "\"" << std::endl;
    }

};


class Lumber : public Distance , public Type
{

    int quantity;
    double price;

    public:
    Lumber() : quantity(0), price(0) {}
    Lumber(int q, double p, int ft, float in, std::string d, std::string g) : quantity(q), price(p),Distance(ft,in), Type(d,g){}

    void getLumber()
    {
        Type :: gettype();
        Distance :: getDistance();
        std::cout << "enter quantity: "; std::cin >> quantity;
        std::cout << "enter price: "; std::cin >> price;

    }

    void showLumber()
    {
        Type::putdata();
        Distance::showDistance();

        std::cout << quantity <<":"<<"$"<<price<<std::endl;
    }

};



// --- MAIN ---
int main()
{
 Lumber l1;
 l1.getLumber();
 l1.showLumber();

 Lumber l2(2,200, 5, 2.5, "breadth", "B" );
 l2.showLumber();


 return 0;
}


