/*

 A shared pointer can share the resource it points to, if a program requires, that multiple objects be shared, then
 one can use this concept.
 The object or resource is destroyed when the last shared pointer to it is destroyed.

*/

#include<iostream>
#include<string>
#include<memory>




int main()
{
 std::string s1 = "Hello World!";

 // create a shared pointer and allocate it mem via make_shared
 std::shared_ptr<std::string> s_ptr1 = std::make_shared<std::string>(s1);

 std::cout<<*s_ptr1<<std::endl;

 // create another shared pointer and make it point to the same resource
 std::shared_ptr<std::string> s_ptr2 = s_ptr1;

 std::cout<<*s_ptr2<<std::endl;

 return 0;
}