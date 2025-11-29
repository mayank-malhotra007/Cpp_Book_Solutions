
#include<iostream>
#include<list>

int main()
{
 std::list<int> l;

 l.push_back(10);
 l.push_back(20);
 l.push_back(30);

 //display
 for(int x:l)
 {
    std::cout << x << " ";
 }


 //size()
 std::cout << "size of list: " << l.size() << std::endl;
 

 // read items from front of list
 while(!l.empty())
 {
    std::cout << l.front() << " ";
    l.pop_front();
 }

 

 return 0;
}