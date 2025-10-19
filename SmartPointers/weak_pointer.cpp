/*
 A weak pointer is a smart pointer that does not own an object, it refers to an object owned by shared_ptr.
 Does not affect the reference count.
 It can just see the object or resource pointed to by the shared_ptr.

 When objects point to each other, this can create a cycle, a livelock.
 Use a weak_ptr here.


*/

#include<iostream>
#include<memory>

int main()
{
 
 std::shared_ptr<int> s1 = std::make_shared<int>(10);


 std::cout<<s1 <<" " <<*s1 <<std::endl;

 // create a weak_ptr, cannot derence a weak_ptr, like void*
 std::weak_ptr<int> wp = s1;

 auto x = wp.lock(); // returning the address of the shared_ptr
 std::cout<<"x: "<<x<<std::endl;

 if(x) {std::cout<<"shared pointer exists"<<std::endl;}


 return 0;
}