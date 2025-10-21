


#include<iostream>

class Distance
{
  int feet;
  float inches;

  public:
    Distance() : feet(0), inches(0) {}

    Distance(int ft, float in): feet(ft), inches(in)
    {
        std::cout << "2args constructor called" << std::endl;
    }

    void showdist()
    {
        std::cout << feet << "\'" << inches << std::endl;
    }

    float square();
};

float Distance :: square()
{
    float f =feet + inches/12;
    std::cout << "feet: " << f << std::endl;
    return (f*f);
}

int main()
{
 Distance d(7,14.2);
 d.showdist();

 float result=d.square();
 std::cout << result << std::endl;


 return 0;
}