/* englconv.cpp */

#include<iostream>
#include<iomanip>

// Distance class
class Distance
{
    const float MTF;
    int feet;
    float inches;

    public:
    Distance(): feet(0), inches(0), MTF(3.28){}

    Distance(float meters): MTF(3.28)
    {
        float fltfeet = MTF*meters;
        feet = int(fltfeet);
        inches = 12*(fltfeet - feet);
    }

    Distance(int ft, float in): feet(ft), inches(in), MTF(3.28)
    {}

    void getdist()
    {
        std::cout << "enter feet: ";
        std::cin >> feet;

        std::cout << "enter inches: ";
        std::cin >> inches;

    }

    void showdist() const
    {
        std::cout << std::fixed << std::setprecision(2)
        << feet << "\"" << inches << "\'"<<std::endl;
    }

    //overload () , in this case the type is after the keyword operator
    operator float ()
    {
        // 1 feet = 0.3048 meters
        std::cout << "operator float() invoked" << std::endl;

        feet = feet + inches/12.0;
        float fltfeet = float(feet);
        float temp = fltfeet / MTF;
        return temp;

    }


};


//  --- MAIN ---
int main()
{
    float mtrs;
    Distance d1(10.45); // calls 1-arg const and converts meters to feet and inches
    d1.showdist();

    mtrs = static_cast<float>(d1); // converts the object, feet and inches into mtrs
    std::cout << "meters: " << mtrs << std::endl;

    //invoke the 2 arg constructor
    Distance d2(7, 3.5);
    d2.showdist();

    mtrs = d2; // also invokes the float()operator
    std::cout << "meters: " << mtrs << std::endl;
    

    return 0;
}