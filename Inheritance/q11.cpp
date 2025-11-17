
#include<iostream>
#include<stack>

struct pair
{
    int x;
    int y;
};






int main()
{
  pair p1;

  std::stack<pair> st;
  
  std::cout << "enter the x coordinate: "; std::cin >> p1.x;
  std::cout << "enter the y coordinate: "; std::cin >> p1.y;

  
   st.push(p1);

   auto obj = st.top();
   st.pop();

   std::cout << obj.x << ":" << obj.y << std::endl; 



 return 0;
}

