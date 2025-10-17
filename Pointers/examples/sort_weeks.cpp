
/* using the sort function from std::sort , sort the week array lexi , asc and dsc.  */

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<array>

void sortWeek(std::array<std::string,7>);
void sortNumbers(std::vector<int>);

int main()
{
  std::vector<int> num = {5, 6, 10, 3, 1, 6, 2, 8, 9,0 };  
  std::array<std::string,7> week = {"Tue", "Wed", "Fri", "Sun", "Sat", "Mon", "Thur" };
  
  for(auto x:week)
  {
    std::cout<<x<<" ";
  } 
  std::cout<<std::endl;
 
  
  sortWeek(week); 
  sortNumbers(num);
  
 
 return 0;
}


void sortWeek(std::array<std::string,7> w)
{ 
    std::cout<<"----- After ASC Sort Week -----"<<std::endl;
    std::sort(w.begin(), w.end());

    for(auto x:w)
    {
        std::cout<<x<<" ";
    }

}

void sortNumbers(std::vector<int> n)
{
  std::cout<<std::endl<<"----- After DSC Sort Numbers -----"<<std::endl;
  std::sort(n.begin(), n.end(), std::greater<int>());
  for(auto x: n)
  {
    std::cout<<x<<" ";
  }
}

