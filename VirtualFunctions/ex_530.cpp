/*
 static data members are created once in memory, no copies and retain their value till the program ends,
 static functions are used to access static data members,
 static functions are called using class name and not object,
 static functions dont have a 'this' pointer
*/

#include<iostream>

class Gamma
{
    static int total; // declaration only
    int id;

    public:
       Gamma ()
       {
        total++;
        id = total;
       }

       ~Gamma()
       {
        std::cout << "destroying id" << id << std::endl;
        total--; 
       }

       static void showtotal()
       {
        std::cout << "total is: " << total << std::endl;
       }

       void showid()
       {
        std::cout << "id number is: " << id << std::endl;
       }
};

// mem allocation
int Gamma :: total=0;

int main()
{
 Gamma g1;
 Gamma::showtotal();

 Gamma g2;
 Gamma::showtotal();

 Gamma g3;
 Gamma::showtotal();

 g1.showid();
 g2.showid();
 g3.showid();

 return 0;
}