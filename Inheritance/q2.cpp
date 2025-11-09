// STRCONV

/*
In C++, a base class constructor cannot be called from the body of a derived class constructor. It can only be invoked in the initializer list.
*/

#include<iostream>
#include<cstring>

const int MAXSIZE = 10;

class String
{
   
    char str[MAXSIZE];

    public:
    String() {
        strcpy(str, " ");
    }

    String(const char s[])
    {
        strcpy(str,s);
    }

    void display() const
    {
        std::cout << str << std::endl;
    }

    // user defined conversion to char*, object to char*
    operator char*()
    {
        return str;
    }

};

class Pstring : public String
{
    int len;
    char new_str[MAXSIZE];
    

    public:
    
    // Pstring(const char ss[]) : String( strlen(ss)>=MAXSIZE ? std::string(ss).substr(0,MAXSIZE-1).c_str() : ss ) 
    
    Pstring(const char ss[]): String (
        [&]()
        {
           len = strlen(ss);
           static char temp[MAXSIZE];
            if(len>=MAXSIZE)
            {
                strncat(new_str, ss, MAXSIZE-1); // if MAXSIZE = 10, MAXSIZE-1 =9, it copies upto 0 to 8.
                new_str[MAXSIZE-1] = '\0';
                
              
                strcpy(temp, new_str);
                
            }

            else
            {
                strcpy(temp,ss);
            }
            return temp; // static is used else, when lambda finishes it the temp pointer is destroyed and String cannot copy it
        } () //invoke the lambda
    )
      
    {
      // body of constructor
    }


};




// --- MAIN ---
int main()
{

    Pstring p1("hello world, its a sunny day");
    p1.display();

    return 0;

}
