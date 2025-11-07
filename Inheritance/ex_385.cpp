/*
englen.cpp ; inheritance
*/

#include<iostream>

enum posneg {pos,neg};

class Distance
{
    protected:
    int feet;
    float inches;

    public:
    Distance() : feet(0), inches(0) {}
    Distance(int ft, float in) : feet(ft), inches(in) {}

    void getdist()
    {
        std::cout << "enter feet: "; std::cin >> feet;
        std::cout << "enter inches: "; std::cin >> inches;
    }


    void showdist() const
    {
        std::cout << "("<<feet << "\"" << inches <<"\'"<<")" << std::endl;
    }
    

};

class DistSign : public Distance
{
  private:
  posneg sign;

  public:
  DistSign() : Distance()
    {
        sign = pos;
    }

  DistSign(int ft, float in, posneg sg=pos) : Distance(ft,in)
  {
    sign = sg;
  }

  void getdist()
  {
    Distance :: getdist();
    char ch;
    std::cout << "enter sign: ";
    std::cin >> ch;

    //conditional operator to check sign + or -
    sign = (ch == '+') ? pos : neg ;
  }

  void showdist() const
  {
    std::cout << ((sign == pos) ? "+" : "-");
    Distance::showdist();
  }
    
};

int main()
{
 DistSign d1;
 d1.getdist();

 DistSign d2(11,6.25);
 DistSign d3(100, 5.5, neg);

 d1.showdist();
 d2.showdist();
 d3.showdist();

 std::cout << std::endl;

 return 0;
}