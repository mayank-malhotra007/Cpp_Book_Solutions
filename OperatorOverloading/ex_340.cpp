
/* arrover1.cpp */

#include<iostream>
//#include<cstdlib>

const int LIMIT = 10;

class SafeArray
{
    int arr[LIMIT];

    public:

    void putel(int n, int elvalue)
    {
        if(n<0 || n>=LIMIT)
        {
            std::cout <<"index out of bounds" << std::endl;
            exit(1);
        }

        arr[n] = elvalue;
    }

    int getel(int n) 
    {
        if(n<0 || n>=LIMIT)
        {
            std::cout <<"index out of bounds" << std::endl;
            exit(1);
        }

        return arr[n];
    }

};



// -- MAIN --
int main()
{
 SafeArray o1;

 // fill in the array
 for(int x=0; x<LIMIT; x++)
 {
    o1.putel(x, x);
 }

 //display
 /*
 for(int y=0; y<LIMIT; y++)
 {
    std::cout << o1.getel(y) << std::endl;
 }*/

 //checks index out of bounds
 o1.getel(100);

 return 0;
}
