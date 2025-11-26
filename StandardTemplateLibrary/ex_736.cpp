
#include<iostream>
#include<algorithm>

int arr[] = {33,22,33,44,33,55,66,77};

int main()
{ 
  int c=std::count(arr, arr+7, 33);
   std::cout << c << std::endl;

  std::cout << *(arr+7) << std::endl;
  std::cout << *(arr +8) << std::endl;


 return 0;
}
