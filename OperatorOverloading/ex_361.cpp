/*
    using explicit : to prevent implicit conversions, affects constructors or conversion operators
*/

#include<iostream>

class Distance
{
    const float MTF;
    int feet;
    float inches;

    public:
    Distance(): feet(0), inches(0), MTF(3.28){}

    explicit Distance(float meters): MTF(3.28)
    {
        float fltfeet = MTF*meters;
        feet = int(fltfeet);
        inches = 12*(fltfeet-feet); 
    }

    

    void showdist() const
    {
        std::cout << feet << "-" << inches << std::endl;
    }

    //converts a distance object to float; user defined conversion
    explicit operator float() 
    {
       float temp = feet + 12*inches;
       return temp;
    }
};


int main()
{
 Distance d1(2.35);

 // Distance d2 = 2.35; // wont work its implicit conversion from double to a Class object
 
 d1.showdist();

 
 float ff;
 
 //ff = d1; // wont work till float() is explicit

 // this is not a function call but a type cast
 ff = float(d1); // == static_cast<float>(d1)

 std::cout << "float value is: " << ff << std::endl;



 return 0;
}