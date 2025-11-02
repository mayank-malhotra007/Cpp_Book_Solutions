
#include<iostream>
#include<iomanip>

class Distance
{
    int feet;
    float inches;

    public:
    Distance() : feet(0), inches(0) {}

    Distance(int ff, float ii): inches(ii), feet(ff) {}

    void display() const
    {
        std::cout << feet << "-" 
        <<std::fixed << std::setprecision(2)
        << inches << std::endl;
    }

    friend Distance operator-(const Distance& lhs, const Distance& rhs);
    
};


Distance  operator-(const Distance&lhs, const Distance& rhs)
{
    float temp_feet_1;
    float temp_feet_2;

    temp_feet_1 = lhs.feet + (lhs.inches)/12;
    temp_feet_2 = rhs.feet + (rhs.inches)/12;

    float diff_feet = 0;

    if(temp_feet_1 > temp_feet_2)
    {
        diff_feet = temp_feet_1 - temp_feet_2;
    }
    else
    {
        diff_feet = temp_feet_2 - temp_feet_1;
    }

    int ft = int(diff_feet);
    float in = 12*(diff_feet-ft);

    return Distance(ft,in);
   

}


int main()
{

 Distance d1(11, 4.5);
 Distance d2(9, 3.4);

 d1.display();
 d2.display();

 Distance d3;
 d3 = d1-d2;

 d3.display();

 return 0;
}