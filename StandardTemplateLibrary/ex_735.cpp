
#include<iostream>
#include<algorithm>
#include<vector>

//int arr [] = {11,22,33};

int main()
{


int arr[] = {11,22,33};


 ptr = std::find(arr, arr+3, 33);
 
 std::cout<<"index: " <<ptr-arr << std::endl;
 std::vector<int> v {100,200,300};

 std::vector<int>::iterator f =std::find(v.begin(), v.end(),200);
 std::cout << "element found at: " << f - v.begin() << std::endl;

 return 0;

}
