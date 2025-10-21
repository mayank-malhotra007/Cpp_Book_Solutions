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
        feet = flt;
        int f = static_cast<int>(flt);
        inches = flt-f;
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

     // operator overloading
     friend Distance operator+ (Distance, Distance);

};


Distance operator+ (Distance lhs, Distance rhs)
{
   int f = lhs.feet + rhs.feet;
   float i = lhs.inches + rhs.inches;

   if(i>=12.0)
   {
    i = i-12.0;
    f++;
   }

   // 2 args constructor is called here
   return Distance(f,i);

  
}


// --- MAIN ---
int main()
{
    Distance d1(10.25); //1 args const called
    Distance d2(11.21); // 1 args const called
    Distance d3;

    d3 = d1 + d2 ;

    d3.showdist();
 

 return 0;
}
