/*  strimem2.cpp

    'this' pointer cannot be used for static member functions,
    static member functions are used to access static data members,
    static member functions are called using class name,
    static member functions do not have an object,
    static member functions cannot access non static data members,
    scoped within a class

*/



#include<iostream>

class String;

class strCount
{
 int count;
 char* str;
 friend String;

 strCount(const char* s)
 {
    str = new char[strlen(s)+1];
    strcpy(str,s);
    count++;
 }

 ~strCount()
 {
    delete[] str;
 }

};



class String
{
  strCount* psc;

  public:
    String(){
        psc = new strCount(" ");
    }

    String(const char* S)
    {
        psc = new strCount(S);
    }

    //copy 
    String(const String& rhs)
    {
        psc=rhs.psc;
        psc->count++;
    }

    //assignment
    String& operator=(const String& rhs)
    {
        psc = rhs.psc;
        psc->count++;

        return *this;
    }

    // display
    void display()
    {
        std::cout << psc->str << " " <<strlen(psc->str) << " " << psc <<std::endl;
        std::cout << "count: " << psc->count << std::endl;
    }


    // destructor
    ~String()
    {
        std::cout << "destructor called" << std::endl;
    }
    

};




int main()
{
  String s1 = "hello world!";

  s1.display();

  String s2(s1);
  s2.display();

  String s3 = s2;
  s3.display();

  String s4;
  s4 = s3;
  s4.display();



  return 0; 
}