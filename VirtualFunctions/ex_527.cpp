/*    implementing sqaure using friend function     */

#include<iostream>

class Distance
{
    int feet;
    float inches;

    public:
    Distance(): feet(0), inches(0) {}

    Distance(int f, float i)
    {
        feet = f;
        inches = i;
    }

    friend float Square(Distance);

};

float Square(Distance d)
{
    d.feet = d.feet + d.inches/12;
    std::cout << "d.feet" << d.feet << std::endl;
    return (d.feet*d.feet);
}


int main()
{
 Distance dd(3,14.5);

 float x = Square(dd);
 std::cout << "Squared: " << x << std::endl;

 return 0;
}
