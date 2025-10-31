/* strconv.cpp */

#include<iostream>
#include<string>
#include<cstring>

class String
{
    enum {SZ=80};
    char str[SZ];

    public:
    String()
    {
        str[0] = '\0';
    }

    String(const char s[])
    {
        std::cout << "1-arg constructor invoked" << std::endl;
        strcpy(str,s);
    }

    void display() const
    {
        std::cout << str << std::endl;
    }

    // method 1, overload operator char*()
    explicit operator char*()
    {
        std::cout << "operator invoked" << std::endl;
        return str;
    }

    // method 2 overload << operator
    friend std::ostream& operator<<(std::ostream& os,const String& s);


};


std::ostream& operator<<(std::ostream& os, const String& s)
{
    os << s.str;
    return os;
        
}


int main()
{
 // Case 1: char* to String
 String s1;
 std::cout <<"s1 type: "<<typeid(s1).name() << std::endl;

 char str1[] = "hello world";
 std::cout <<"str1 type: "<<typeid(str1).name() << std::endl;

 s1 = str1; // 1-arg const invoked; conversion from char* to String
 s1.display();

 // Case 2: char* to String
 String s2 = "today is a good day!";
 // the above decays to String s2 = (const char*)"today is a good day!";

 char str2[20];
 std::cout << static_cast<char*>(s2); // converts object of class String to char*
 std::cout << std::endl;
 std::cout << (char*)s1;

 //Note so either overload operator char*() to print a string from an object or overload std::cout << operator

 std::cout << std::endl;
 std::cout << s1 << std::endl;

 return 0;
}
