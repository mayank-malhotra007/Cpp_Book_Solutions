/*
    Overload < and > operators to compare distances
*/

#include<iostream>


class Distance
{
    int feet;
    float inches;
    
    public:
    Distance(){}

    Distance(int ff, float in): feet(ff), inches(in) 
    {
        if(inches>=12.0)
        {
            inches-=12.0;
            feet++;
        }
    }
    
    void display()
    {
        std::cout << feet << "-" << inches << std::endl;
    }

    bool operator<(Distance& rhs)
    {
        float temp_lhs = feet + inches/12.0;
        float temp_rhs = rhs.feet + rhs.inches/12.0;

        if(temp_lhs < temp_rhs) return true;
        else return false;

    }


};


// --- MAIN ---
int main()
{
 Distance d1(5, 2.2);
 Distance d2(5, 2.3);

 std::cout << (d1<d2 ? 1 : 0) << std::endl;

 return 0;
}