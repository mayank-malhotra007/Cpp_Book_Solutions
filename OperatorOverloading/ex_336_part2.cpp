/* String compare of char arrays */

#include<iostream>

class String
{
    char str[50];

    public:
    String(char s[])
    { 

        strcpy(str,s);
    }

    void display()
    {
        std::cout << str << std::endl;
    }

    void operator=(String& rhs)
    {
        if(strcmp(str,rhs.str)==0)
        {
            std::cout << "strings are same" << std::endl;
        }
        else
        {
            std::cout << "strings are not the same" <<std::endl;
        }
    }

};

int main()
{
    char str1[] = "oko";
    char str2[] = "ok";

    String s1(str1);
    String s2(str2);

    s1 = s2;

    return 0;
}
