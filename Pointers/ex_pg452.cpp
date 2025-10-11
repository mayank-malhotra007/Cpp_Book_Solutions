/* string */

#include<iostream>
#include<string>

int main() {

 
 char str1[] = "abcdef";
 std::string s = "xzy";
 std::string* ptr_s = &s;

 std::cout<<"str1: "<<str1<<std::endl;
 std::cout<<"str2: "<<*ptr_s<<std::endl;



 return 0;
}