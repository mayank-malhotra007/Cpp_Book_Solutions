/*
 Polar coordinates (radius and angle)
 Rectangular coordinates ( x & y coordinates)

 Task: take in polar coordinates, covert into rectangular and print then convert back to polar and print  
 To add 2 rectangular coordinates , overload the + operator

 Conversion logic: x = r.cos(angle), y = r.sin(angle)
*/

#include<iostream>
#include<cmath>

class Rectangle;

class Polar
{
    float radius;
    int angle;

    public:
    Polar():radius(0), angle(0) {}

    Polar(float r, int theta) : radius(r), angle(theta) {}

    // returns an object of class Polar
    Polar& get_polar()
    {
        return *this;
    }

    int get_angle() {return angle;}
    float get_radius() {return radius;}

    void display()
    {
        std::cout << radius << "r" << " " << angle << "\u00B0" << std::endl;
    }

    friend Rectangle;

};

class Rectangle
{    

    int x;
    int y;

    public:
    Rectangle(): x(0), y(0) {}
    Rectangle(int a, int b): x(a), y(b) {}

    
    // friend function to convert polar to rectangular
    friend Rectangle operator+ (Polar& lhs, Polar& rhs);
  
    void display()
    {
        std::cout << x << "," << y << std::endl;
    }

};



Rectangle operator+ (Polar& lhs, Polar& rhs)
{
    float r1 = lhs.get_radius();
    float r2 = rhs.get_radius();

    int a1 = lhs.get_angle();
    int a2 = rhs.get_angle();

   int x1 = r1 * std::cos(a1);
   int y1 = r1 * std::sin(a1);

   int x2 = r2 * std::sin(a2);
   int y2 = r2 * std::sin(a2);

   int temp_x = x1 + x2;
   int temp_y = y1 + y2;



   return Rectangle(temp_x, temp_y);

}


// -- MAIN --
int main()
{
 Polar p1(10, 45);
 Polar p2(5, 90);

 p1.display();
 p2.display();

 Rectangle r = p1 + p2;
 r.display();


 return 0;
}