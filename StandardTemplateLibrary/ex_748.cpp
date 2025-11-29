
#include<iostream>
#include<list>

// --- MAIN ---
int main()
{
 int j;
 std::list<int> l1,l2;

 int arr1[] = {40,30,20,10};
 int arr2[] = {15,20,25,30,35};

 // init the list1
 for(int x=0; x<4; x++)
 {
    l1.push_back(arr1[x]);
 }

 // init the list2
 for(int x=0; x<5; x++)
 {
    l2.push_back(arr2[x]);
 }

 //display list1 and list2
 for(int j:l1)
 {
    std::cout << j << " ";
 }

 std::cout << std::endl;
 for(int k:l2)
 {
    std::cout << k << " ";
 }


 std::cout << std::endl;
 
 //reverse the list
 l1.reverse();
 for(int j:l1)
 {
    std::cout << j << " ";
 }

 std::cout << std::endl;


 // merge two lists
 l2.merge(l1);
 for(int k:l2)
 {
    std::cout << k << " ";
 }

 std::cout << std::endl;

 
 // make unique
 l2.unique();
  for(int k:l2)
 {
    std::cout << k << " ";
 }

 std::cout << std::endl;


 // get the size
 std::cout << l2.size();

 

 return 0;
}