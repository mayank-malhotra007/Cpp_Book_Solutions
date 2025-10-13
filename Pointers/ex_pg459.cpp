/* new operator*/
#include<iostream>
#include<cstring>

int main() {
 
   const char* str = "Hi Today is a good day!";
   int len = strlen(str);
   std::cout<<len;
  
   char* ptr;
   ptr = new char[len+1]; // malloc goes into heap memory
  
   std::cout<<std::endl;
   strcpy(ptr,str);
   std::cout<<ptr;

   delete ptr;
    return 0;
}