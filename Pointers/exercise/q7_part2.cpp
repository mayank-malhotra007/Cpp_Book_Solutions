
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

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
    

};

void Person :: setData()
{
    std::cout<<"enter the name: ";
    std::cin>>name;
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




// ---- MAIN -----
int main()
{
  Person p1,p2,p3;

  p1.setData();
  p2.setData();
  p3.setData();
 

  // a vector of pointers to class objects
  std::vector<Person*> employee {&p1, &p2, &p3};

  std::cout<<"--- before sorting ---"<<std::endl;
  for(auto x:employee)
  {
    x->printData();
    std::cout<<std::endl;
  }
  
  // if it was a vector of objects and not pointers, we just use p1.getSalary(), p2.getSalary()
  std::sort(employee.begin(), employee.end(), [](Person* p1, Person* p2){return p1->getSalary() < p2->getSalary();});
  
  std::cout<<"--- after sorting ---"<<std::endl;
  for(auto x:employee)
  {
    x->printData();
    std::cout<<std::endl;
  }

  return 0;    
}