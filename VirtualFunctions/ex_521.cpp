
/*.  Friend Functions  */

#include<iostream>

class beta;

class alpha
{
    private:
     int data;

    public: 
     alpha() : data(3){};
     friend int frifunction(alpha, beta);
};


class beta
{
    int data;

    public:
     beta() : data(7) {}

     friend int frifunction(alpha, beta);
};


int main()
{
 alpha aa;
 beta bb;

 
 int result = frifunction(aa,bb);

 std::cout << result << std::endl;

 return 0;
}


int frifunction(alpha aa, beta bb)
{
    return (aa.data + bb.data);
}