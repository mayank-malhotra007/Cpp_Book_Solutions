/*
    Concatenate Strings
*/

#include<iostream>
#include<string>
#include<algorithm>

class String
{
    char str[100];

    public:
    String() 
    {
        strcpy(str," ");
    }

    String(const char arr[])
    {
        strcpy(str,arr);
    }

    void display()
    {
        std::cout << str << std::endl;
    }

    const char* getString()
    {
        return str;
    }

    String operator+(const String& rhs)
    {
        strcat(str, " ");
        strcat(str, rhs.str);
        return *this;
    }
};




// -- MAIN --
int main()
{
  String s;
  String s1("hello");
  String s2("world!!");

  s = s1 + s2;
  s.display();

  std::cout << typeid(s).name() << std::endl;
  
  const char* ss = s.getString();
  std::cout << ss << std::endl;
  std::cout << typeid(ss).name() << std::endl;


  // converted a const char* to a std::string
  std::string expr;
  int i=0;
  while(i<strlen(ss))
  {
    char ch = ss[i];
    expr+=ch;
    i++;
  }  

  std::cout << expr << std::endl;
  std::cout << typeid(expr).name() << std::endl;

  // check size
  std::cout << expr.size() << std::endl;
  
  // return iterators
  auto start = expr.begin();
  auto end = expr.end();

  while(start<end)
  {
    std::cout << *start; 
    start++;
  }

  std::cout << std::endl;

  // find an element and remove it
  int index = expr.find("!!");
  std::cout << "index is: " << index << std::endl;

  // using at() 
  std::cout << expr.at(11)<<std::endl;

  // remove !
  expr.erase( std::remove(expr.begin(), expr.end(), '!'), expr.end() );
  std::cout << expr << std::endl;

  // remove spaces
  expr.erase(std::remove_if(expr.begin(), expr.end(),
                          [](unsigned char x){ return std::isspace(x); }),
            expr.end());


  std::cout << expr << std::endl;

  // convert all to upper case, .data() returns a const char* to the first of the string expr
  const char* cc = expr.data();

  std::string new_str;
  int x=0;
  while(x<strlen(cc))
  {
    char ch = std::toupper(cc[x]);
    new_str+=ch;

    x++;
  }
   
  // all caps
  std::cout << new_str << std::endl;
  return 0;
}