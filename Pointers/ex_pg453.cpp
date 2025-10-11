/* string as function args*/

#include<iostream>
#include<string>

void printString(std::string& );
void displayString(std::string*);

// -- MAIN --
int main()
{
 std::string str = "abcd";

 printString(str);

 std::string* ptr = &str;
 displayString(ptr);


 return 0;
}

// pass as reference
void printString(std::string& s)
{
    std::cout<<"string is: "<<s<<std::endl;
}


// pass as pointer
void displayString(std::string* p)
{
   if(p != nullptr)
   {
    std::cout<<*p;
   }
}
