/*
An aggregation is a weak "has-a" relationship, create references of the whole, pass it to a function or constructor of the part!


The part can exist without the whole.
E.g : a car can exist without an antenna, but not without an engine.
*/

#include<iostream>

class Student
{
    std::string school;
    std::string degree;

    public:
    void getEdu()
    {
        std::cout <<"enter school: "; std::cin >> school;
        std::cout <<"degree "; std::cin >> degree;
    }

    void putEdu()
    {
        std::cout << school << ":" << degree << std::endl;
    }
};


class Employee
{
    std::string name;
    unsigned long number;

    public:
    void getEmp()
    {
        std::cout << "enter name: "; std::cin >> name;
        std::cout << "enter number: "; std::cin >> number;
    }

    void showEmp()
    {
        std::cout << name << ":" << number << std::endl;
    }
};


// manager has- a employee but employee can exist without the manager
class Manager
{
    std::string title;
    double dues;
    
   

    public:
    void getManager(Student* st, Employee* emp)
    {
        emp->getEmp();
        st->getEdu();   
        std::cout << "enter title: "; std::cin>>title;
        std::cout << "enter dues: "; std::cin >> dues;
        
       
    }   

    void showManager(Student* st, Employee* emp)
    {
        emp->showEmp();
        st->putEdu();
        std::cout << title << ":" << dues << std::endl;
       
    }

};


// --- MAIN ---
int main()
{

 Student stu;
 Employee emp;

 Manager m1;
 m1.getManager(&stu, &emp);
 m1.showManager(&stu, &emp);


 return 0;
}