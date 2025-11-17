// arrover3.cpp extended

#include<iostream>
const int LIMIT = 10;

class Safearray
{
    
    int arr[LIMIT];
    int LOWER;
    int UPPER;

    public:
    Safearray() : LOWER(0), UPPER(0) {}
    Safearray(int l, int u) : LOWER(l), UPPER(u) {}

    int& operator [](int n)
    {
        if(n<LOWER || n>=UPPER)
        {
            exit(1);
        }
        else
        {
            return arr[n];
        }
    }
};


class safehilo : public Safearray
{
    public:
    safehilo(int L, int H) : Safearray(L,H)
    {
        //body of constructor
    }

};


int main()
{

 safehilo a1(0,10);

 //fill in the array
 for(int i=0; i<LIMIT; i++)
 {
    a1[i] = i * 10;
 }       

 //display
 std::cout << "[ ";
 for(int j=0; j<LIMIT; j++)
 {
    std::cout << a1[j] << " ";
 }
 std::cout << "]";

 std::cout << std::endl;

 return 0;
}