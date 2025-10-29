/* arrover2.cpp */
/* single function to fill in an array and print  */


#include<iostream>
const int LIMIT = 10;



class safearray
{
 int arr[LIMIT];

 public:

 int& access(int n)
 {
    if(n<0 || n>LIMIT)
    {
        std::cout << "out of bounds" << std::endl;
        exit(1);
    }

    return arr[n];
 }
};



// -- MAIN --
int main()
{
 safearray s1;

 // fill in
 for(int x=0; x<LIMIT; x++)
 {
    // here is the trick, x*5 gets placed at s1[x]
    s1.access(x) = x*5;

 }

 // display
 for(int y=0; y<LIMIT; y++)
 {
    int result = s1.access(y);
    std::cout << result << " " << std::endl;

 }


 return 0;
}

