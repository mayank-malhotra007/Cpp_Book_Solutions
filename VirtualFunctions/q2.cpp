
#include<iostream>

class Distance
{
    int feet;
    float inches;

    public:
    Distance(): feet(0), inches(0){}
    Distance(int f, float i): feet(f), inches(i) {}

    void showdist()
    {
        std::cout <<feet<<"-"<<inches << std::endl;
    }

    
    friend Distance operator*(const Distance& ,const Distance& );
    friend Distance operator*(const Distance&, const float );
    //friend Distance operator*(const float , const Distance &);

};

Distance operator*(const Distance& lhs,const Distance& rhs)
{
    int ff = lhs.feet*rhs.feet;
    float ii = lhs.inches*rhs.inches;
    if(ii>=12.0)
    {
        ii-=12.0;
        ff++;
    }

    return Distance(ff,ii);
}


Distance operator*(const Distance& lhs, const float rhs)
{
  //rhs = 15.26
  int x = static_cast<int>(rhs); // x = 15, gets feet
  int y = 12*(rhs-x); // to get inches , y = 0.26*12

  int ff = lhs.feet*x;
  float ii = lhs.inches*y;

  if(ii>=12.0)
    {
        ii-=12.0;
        ff++;
    }

 return Distance(ff,ii);
}







// --- MAIN ---
int main()
{
 Distance d1(2,5.5);
 Distance d2(3,2.3);

 d1.showdist();
 d2.showdist();

 Distance d3;
 d3 = d1*d2;

 d3.showdist();

 Distance d4;
 d4 = d1*10.25;
 d4.showdist();




 return 0;
}
