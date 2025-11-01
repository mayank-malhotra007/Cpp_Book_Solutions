/*
    mutable,
    A constant object is one which cannot modify its data members after being created,
    A const object can only access const member functions.
*/

#include<iostream>
#include<string>

class scrollbar
{   
    int size;
    
    mutable std::string owner;
    
    static int a, b;
    int c;

    public:
    scrollbar(int sz, std::string ss): size(sz), owner(ss) {}
    
    // if setSize is made const, then size has to be made mutable since its value is updating, or leave it as it is and dont call it
    void setSize(int sz) 
    {
        size = sz;
        // std::cout << sz << std::endl; // this is possible
    }

    void setOwner(std::string ss) const
    {
        owner = ss;
    }

    std::string getOwner() const
    {return owner;}

    int getSize() const
    {return size;}

    static void add()
    {
        //int temp = a+c;
        int temp = a+b ; // a static member function can access only a static data member
    }

};

// -- MAIN --
int main()
{
    const scrollbar bar(10,"bart");
    bar.getSize();
    bar.getOwner();

    bar.setSize(20); // since bar is a const object it cannot change its data members after its creation
    bar.setOwner("lola");




}