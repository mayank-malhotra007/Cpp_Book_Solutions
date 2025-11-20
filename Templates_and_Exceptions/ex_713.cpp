
#include<iostream>

class Distance
{
    int feet;
    float inches;

    public:
    class InchesEx
    {};

    Distance() : feet(0), inches(0) {}
    Distance(int ft, float in) 
    {
        if(in>=12.0)
        {
            throw InchesEx();
        }
        else
        {
            feet = ft;
            inches = in;
        }
    }

    void showdist()
    {
        std::cout << feet << "\'" << inches << "\"" << std::endl;
    }


};

// --- MAIN ---
int main()
{
 
   try{

        Distance d1(5,17.5);
   
    } 
   catch(Distance::InchesEx)
   {
    std::cout << "inches greater than 12";
   }

 return 0;
}