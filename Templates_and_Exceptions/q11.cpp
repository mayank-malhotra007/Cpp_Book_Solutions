#include<iostream>

class String
{
 static const int SIZE = 10;
 char str[SIZE];
 int len;

 public:
 String(const char arr[]) : len(strlen(arr))
 {
    if(len>=SIZE){
        throw "string too large!"; // reduces to const char*
        // or
        // std::string("string too large!"); then catch via std::string&
    }
    else{
        strcpy(str, arr);
    }
 }

 void display()
 {
    std::cout << str << std::endl;
 }

    
};



// --- MAIN ---
int main()
{

 try{
    String s("hello world");
    
 }catch(const char* ss)
 {
    std::cout << ss << std::endl;
 }
    
 

 return 0;
}