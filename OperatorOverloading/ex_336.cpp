/*  Compare strings  */

#include<iostream>
#include<string>

class String
{
    std::string str;

    public:
    String(std::string s): str(s) {}

    void display()
    {
        std::cout << str << std::endl;
    }

    void operator<(String& rhs)
    {
        int result = str.compare(rhs.str);
        std::cout << result << std::endl;

        if(result<0)
        {
            std::cout << str << " comes before " << rhs.str << std::endl;
        }
        else if (result > 0)
        {
             std::cout << str << " comes after " << rhs.str << std::endl;
        }
        else 
        {
            std::cout << "strings are the same" << std::endl;
        }
        
    }   

};



int main()
{ 
 String s1("abc");
 String s2("bcd");

 s1 < s2;

 return 0;
}