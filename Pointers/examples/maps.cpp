/* using std::map  to sort a week array */

#include<iostream>
#include<map>
#include<string>
#include<vector>

int helper(std::vector<std::string>);
void order(std::vector<std::string>&);

std::map<std::string, int> week = { {"Mon",1}, {"Tue",2}, {"Wed",3}, {"Thur",4}, {"Fri",5}, {"Sat",6}, {"Sun", 7} };
std::vector<std::string> v = {"Sun", "Sat", "Mon", "Wed", "Fri", "Tue", "Thur"};

// ---- MAIN ----
int main()
{
 std::cout<<"--- before sorting ----"<<std::endl;
 for(auto x:v)
 {
    std::cout<<x<<" ";
 }

 order(v);
 std::cout<<"--- after sorting ----"<<std::endl;
 for(auto x:v)
 {
    std::cout<<x<<" ";
 }
 
 return 0;
}


// ---- helper function ----
int helper(std::string x)
{
    int result; 

    if(x == "Mon"){ result = week["Mon"];}
    else if(x == "Tue") {result =week["Tue"];}
    else if(x == "Wed") {result =week["Wed"];}
    else if(x == "Thur") {result = week["Thur"];}
    else if(x == "Fri") {result = week["Fri"];}
    else if(x == "Sat") {result = week["Sat"];}
    else if(x == "Sun") {result = week["Sun"];}
    else {return 8;}
 
 return result;
}


// --- order ----
void order(std::vector<std::string>& v)
{
    //std::cout<<v.size();
    for(int i=0; i<v.size()-1; i++)
    {
        for(int j=i+1; j<v.size(); j++)
        {
            if(helper(v[i])>helper(v[j]))
            {
                auto temp = v[i];
                v[i]=v[j];
                v[j] = temp;
            }
        }
    }

}