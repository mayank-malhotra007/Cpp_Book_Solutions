#include<iostream>
#include<vector>

int main()
{
 double arr[] = {1.1, 2.2, 3.3, 4.4};

 std::vector<double> v = {arr, arr+4};

 std::vector<double> v2(4);

 for(double x:v)
 {
    std::cout << x << " ";
 }

 // swap
 v.swap(v2);

 for(double x:v)
 {
    std::cout << x << " ";
 }

 // back() , pop_back(), empty()
 while(!v.empty())
 {
    std::cout << v.back();
    v.pop_back();
 }

 return 0;
}