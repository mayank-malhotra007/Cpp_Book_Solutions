

#include<iostream>
#include<vector>

int main()
{

 int arr[] = {100, 110, 120, 130};
 
 std::vector<int> v = {arr, arr+4};

 for(int x:v)
 {
    std::cout << x << " ";
 }

 //insert
 v.insert(v.begin()+4,140);
 
 std::cout << std::endl;

 for(int x:v)
 {
    std::cout << x << " ";
 }

 //erase
 v.erase(v.begin()+2);

 std::cout << std::endl;

 for(int x:v)
 {
    std::cout << x << " ";
 }



 return 0;
}