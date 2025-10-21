/*  Distance Example  */

#include<iostream>

class Distance
{
    private:
     int feet;
     float inches;

    public:
     Distance():feet(0), inches(0){}


     Distance(float flt)
     {
        int f = static_cast<int>(flt);
        feet = f;
        inches = 12.0*(flt-f); 
     }

     Distance(int f , float i)
     {
        feet = f;
        inches = i;
     }
    
     void showdist()
     {
        std::cout << feet << "\'" << inches << std::endl;
     }

     // operator overloading, is a member function
     Distance operator+ (const float);
     Distance operator+ (const Distance& rhs);



};


Distance Distance :: operator+ (const float rhs)
{
    std::cout << "called operator+ version1" << std::endl;

    int f = static_cast<int>(rhs);
    float i = 12.0*(rhs -f);

    f = feet+f;
    i = inches+i;

    if(i>=12.0)
    {
        i = i-12.0;
        f++;
    }

   // 2 args constructor is called here
   return Distance(f,i);

  
}


Distance Distance :: operator+(const Distance& rhs)
{
   // this is the lhs = object d1
   std::cout << "called operator+ version2" << std::endl;

   int f = (rhs.feet);
   float i = rhs.inches;

   f = feet+f;
   i = inches +i;

    if(i>=12.0)
    {
        i = i-12.0;
        f++;
    }
   return Distance(f,i);
}



// --- MAIN ---
int main()
{
    Distance d1(10.25); //1 args const called
    Distance d2(11.21); // 1 args const called
    Distance d3;

    d3 = d1 + 11.21; // d1.operator(11.21), calls first version
    d3.showdist();

    d3 = d1 + d2;   // calls second version

    d3.showdist();
 

 return 0;
}
