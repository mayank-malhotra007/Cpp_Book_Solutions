/* overloading binary operators */
#include<iostream>

class Distance
{
    int feet;
    float inches;

    public:
    Distance(int ff, float in): feet(ff), inches(in) {}

    void getdist()
    {
        std::cout << "enter feet: ";
        std::cin  >> feet;
        std::cout << "enter inches: ";
        std::cin  >> inches;

    }

    void showdist()
    {
        std::cout << feet << "-" << inches << std::endl;
    }
 
    friend Distance operator+(const Distance&, const Distance& );
};

Distance operator+(const Distance& lhs, const Distance& rhs)
{
   int ff = lhs.feet + rhs.feet;
   float in = lhs.inches + rhs.inches;

   if(in>=12.0)
   {
     in-=12.0;
     ff+=1;
   }

   return Distance(ff,in);
}

// --- MAIN ---
int main()
{
 Distance d1(0,0);
 Distance d2(0,0);
 
 d1.getdist();
 d2.getdist();

 d1.showdist();
 d2.showdist();

 Distance d3 = d1 + d2;
 
 d3.showdist();

 return 0;
}


