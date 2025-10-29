/* englpleq.cpp */

#include<iostream>

class Distance
{
    int feet;
    float inches;

    public:
    Distance(): feet(0), inches(0){}
    Distance(int ff, float in): feet(ff),inches(in){}

    void getdist()
    {
        std::cout << "enter feet: ";
        std::cin>>feet;
        std::cout << "enter inches: ";
        std::cin>>inches;
    }

    void showdist()
    {
        std::cout << feet << "-" << inches <<std::endl;
    }

    void operator+=(Distance);
    
};


void Distance :: operator+=(Distance d2)
{
    feet += d2.feet;
    inches += d2.inches;

    if(inches>=12.0)
    {
        inches-=12.0;
        feet++;
    }
}




// --- MAIN ---
int main()
{
    Distance d1(10,5.5);
    Distance d2;

    d2.getdist();
    
    d1.showdist();
    d2.showdist();

    d2+=d1; // overloading invoked

    d1.showdist();
    d2.showdist();

    return 0;
}