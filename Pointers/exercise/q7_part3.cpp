
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Person
{
 protected:

    float salary;
    std::string name;
    

 public:
    

    void setData();
    void printData();
    std::string getData();
    float getSalary();
    
    ~Person()
    {
        std::cout<<"destructor called"<<std::endl;
    }
    

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


void salsort(Person** pp, int len)
{
    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            //std::cout<<std::endl;
            //std::cout<<*(pp+i)<<std::endl;
            //std::cout<<*(pp+j)<<std::endl;
            if((*(pp+i))->getSalary() > (*(pp+j))->getSalary())
            //if(pp[i]->getSalary() > pp[j]->getSalary())
            {
                auto* temp = *(pp+i);
                *(pp+i) = *(pp+j);
                *(pp+j) = temp;
            }
        }
    }

}



// ---- MAIN -----
int main()
{
  
  
  Person* names[3];
  

  for(int x=0;x<3; x++)
  {
    *(names+x) = new Person;
    (*(names+x))->setData();
  }

  std::cout<<" ---- before sorting ----"<<std::endl;

  for(int x=0; x<3;x++)
  {
    (*(names+x))->printData();
  }
  
  salsort(names,3);

  std::cout<<" ---- after sorting ----"<<std::endl;
 
  for(int x=0; x<3;x++)
  {
    (*(names+x))->printData();
    delete *(names+x);
  }


  return 0;    
}