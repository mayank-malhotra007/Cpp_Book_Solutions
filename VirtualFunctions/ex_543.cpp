/* strimem.cpp */

#include<iostream>
#include<cstring>

class strCount
{
    int count;
    char* str;
    friend class String;

    strCount(const char* s)
    {
        std::cout << "strCount 1 arg const. called" << std::endl;
        int l = strlen(s);
        str = new char[l+1];
        strcpy(str,s);
        count=1;
    }

    ~strCount()
    {
        delete[] str;
    }
};



class String
{
    strCount* psc; // psc is pointer to object of type class strCount

    public:
    String()
    {
        psc = new strCount("NULL"); 
    }

    //1-arg constructor
    String(const char* s)
    {
        std::cout << "String 1 arg const called " << std::endl;
        psc = new strCount(s); // 1 arg constructor of the strCount is invoked;
    }

    //copy constructor
    String(String& S)
    {
        std::cout << "copy constructor called" << std::endl;
        psc = S.psc;
        (psc->count)++;
    }

    ~String()
    {
        std:: cout << "destructor called" << std::endl;
        if(psc->count==1)
        {
            delete psc;
        }
        else
        {
            --(psc->count);
        }
    }

    void display()
    {
        std::cout << psc->str << std::endl;
    }

    //copy assignment
    void operator=(const String& S)
    {
        std::cout << "copy assignment called" <<std::endl;
        if(psc->count==1)
        {
            delete psc;
        }
        else
        {
            (psc->count)--;
        }
        
        psc = S.psc;
        (psc->count)++;
    }

};


int main()
{
 String s1 = " Hello World!";
 String s2(s1);   
 String s3 = s1;
 String s4;
 s4 = s1;

 s1.display();
 s2.display();
 s3.display();
 s4.display();

 return 0;
}