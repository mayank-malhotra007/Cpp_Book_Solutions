
#include<iostream>
#include<string>
#include<vector>

class Person
{
 protected:
    std::string name;
    float salary;

 public:
    void setData();
    void printData();
    std::string getData();
    float getSalary();
    std::vector<std::string> salsort(Person&);

};

void Person :: setData()
{
    std::cout<<"enter the name: ";
    std::cin>>name;

    std::cout<<std::endl;
    std::cout<<"enter salary: ";
    std::cin>>salary;
}

void Person :: printData()
{
    std::cout<<"name: "<<name<<std::endl;
    std::cout<<"salary: "<<salary<<std::endl;
}

std::string Person :: getData()
{
  return name;
}

float Person :: getSalary()
{
    return salary;
}

std::vector<std::string> Person :: salsort(Person& pp)
{
    std::vector<std::string> n; 
    if(this->salary>pp.salary)
    {
       n.push_back(pp.name);
       n.push_back(this->name);
       
    }else
    {
        n.push_back(this->name);
        n.push_back(pp.name);
    }

    return n;
}


// ---- MAIN -----
int main()
{
  Person p1;
  Person p2;

  p1.setData();
  p2.setData();

  std::vector<std::string> v;
  v = p1.salsort(p2);

  // sorted names as per salary
  for(auto x:v)
  {
    std::cout<<x<<" ";
  }

  return 0;    
}