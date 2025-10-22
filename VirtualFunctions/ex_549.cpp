/* using this pointer to return values , it points to the object of the class */

#include<iostream>

class alpha
{
    int data;

    public:
     alpha(){}
     alpha(int d)
     {
        data = d;
     }

     void display()
     {
        std::cout << data << std::endl;
        std::cout << this->data << std::endl;
     }

     alpha& operator=(alpha& a)
     {
        data = a.data;
        return *this;
     }

};


int main()
{
 alpha a1(10);
 alpha a2;
 a2 = a1;

 a1.display();
 a2.display();


 return 0;
}
