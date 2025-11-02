/*
    STRPLS modified
*/

#include<iostream>
#include<cstring>



class String
{

    char arr[20];

    public:
    String()
    {
        strcpy(arr," ");
    }

    String(const char str[])
    {
        strcpy(arr,str);
    }


    void display()
    {
        std::cout << "string is: " << arr << std::endl;
    }

    // return by value
    /*
    String operator+=(String& rhs)
    {
        strcat(arr, " ");
        strcat(arr, rhs.arr);
        
        return String(arr);
    }
    */


    // return by reference
    String& operator+=(String& rhs)
    {
        strcat(arr, " ");
        strcat(arr, rhs.arr);

        return *this; // return the current object by reference
        //return String(arr);
    }


};



// --- MAIN ---
int main()
{
    String s1 = "Hello"; // they reduce to const char*
    String s2 = "World";

    String s3;
    
    std::cout << "s1: "; s1.display();
    std::cout << "s2: "; s2.display();

    //overloaing +=
    s1 += s2;

    std::cout << "s1: ";
    s1.display();

    //overloading +=
    s3 = s1 += s2;

    std::cout << "s3: ";
    s3.display();


}