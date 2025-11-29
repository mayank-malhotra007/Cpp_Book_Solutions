#include<iostream>
#include<vector>

int main()
{
 int arr[] = {100,110,120,130};

 // init a vector
 std::vector<int> v(arr,arr+4);
 for(int x:v)
 {
    std::cout << x << " ";
 }

 std::cout << std::endl;
 
 // -- insert
 v.insert(v.begin()+2, 150);
 for(int x:v)
 {
    std::cout << x << " ";
 }
 
 std::cout << std::endl;

 // -- erase
 v.erase(v.begin()+3);
 for(int x:v)
 {
    std::cout << x << " ";
 }


 return 0;
}