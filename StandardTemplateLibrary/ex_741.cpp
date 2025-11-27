#include<iostream>
#include<string>
#include<algorithm>

bool isDon(std::string name)
{
    return name == "Don";
}

std::string names[] = {"george", "estelle", "Don"};

int main()
{
  std::string* ptr;

   ptr = find_if(names, names+3, isDon);
   
   if(ptr == names+3)
   {
    std::cout << "no match found" << std::endl;
   }
   else
   {
    std::cout << "found: " << *ptr << std::endl;
   }

 return 0;
}