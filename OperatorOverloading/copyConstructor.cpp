
#include<iostream>

class Employee
{
    int age;
    float salary;
    std::string name;

    public:
        Employee(int a, float f, std::string s): age(a), salary(f), name(s) {}

        //copy constructor
        Employee(const Employee& rhs)
        {
            std::cout<<"copy const. called"<<std::endl;
            age = rhs.age;
            salary = rhs.salary;
            name = rhs.name;
        }

        //copy assignment
        Employee& operator=(const Employee& rhs)
        {
            std::cout<<"copy assignment called"<<std::endl;
            age = rhs.age;
            salary = rhs.salary;
            name = rhs.name;
            
            // here this is a pointer to the calling object, e3 and *this is e3 itself
            return *this;
        }

        // move constructor
        Employee(Employee&& rhs)
        {
            std::cout<<"move const. called"<<std::endl;
            age    = std::exchange(rhs.age, 0);
            salary = std::exchange(rhs.salary,0.0f);
            name   = std::exchange(rhs.name, std::string());
            
        }

        // move assignment
        Employee& operator=(Employee&& rhs)
        {
            std::cout<<"move assignment called"<<std::endl;
            age    = std::exchange(rhs.age, 0);
            salary = std::exchange(rhs.salary,0.0f);
            name   = std::exchange(rhs.name, std::string());
            return *this;
            
        }


        // display 
        void display()
        {
            std::cout<<name<<" "<<age<<" "<<salary<<std::endl;
        }

};


int main()
{
 Employee e1(10,100,"lola");
 Employee e2(e1); // copy constructor is invoked

 e1.display();
 e2.display();

 Employee e3 = e2; // copy constructor
 e3.display();

 Employee e4 (std::move(e3)); // move const called

 Employee e5(20,200,"mila");
 e5 = std::move(e4);   // move assignment is called
 e5.display();

 Employee e6(10,200,"lulu");
 e6 = e1; // copy assignment called
 e6.display();

 return 0;
}