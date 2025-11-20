
#include<iostream>

class Distance
{
    int feet;
    float inches;

    public:
    class InchesEx
    {
        public:
        std::string origin;
        float iValue;

        InchesEx(std::string msg, float f)
        {
            origin = msg;
            iValue = f;
        }
    };

    Distance() : feet(0), inches(0) {}
    Distance(int f, float i) 
    {
        if(i>=12.0)
        {
           throw InchesEx("inches overflow", i);

        }

        feet = f;
        inches = i;
    }

    void getdist()
    {
        std::cout << "enter feet: "; std::cin>> feet;
        std::cout << "enter inches: "; std::cin >> inches;

        if(inches>=12.0)
        {
            throw InchesEx("inches overflow", inches);
        }
    }

    void display()
    {
        std::cout << feet << "\'" << inches <<"\"" << std::endl;
    }

};


// --- MAIN ---
int main()
{
 try
 {
    //Distance d1(10, 13.5);

    Distance d2;
    d2.getdist();


 }catch(Distance :: InchesEx& obj)
 {
    std::cout << obj.origin << ":" << obj.iValue << std::endl;
 }



 return 0;
}