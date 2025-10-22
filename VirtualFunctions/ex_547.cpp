/* this pointer */

#include<iostream>


class where
{
    char arr[10];

    public:
     void reveal()
     {
        std::cout << "object addr is " << this << std::endl;
     }
};


int main()
{
 where w1,w2,w3;

 w1.reveal();
 w2.reveal();
 w3.reveal();


 return 0;
}