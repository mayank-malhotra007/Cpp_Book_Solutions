/*     Multiple Inheritance  */

// class Manager   : public Employee, public Student
// class Scientist : public Employee, public Student
// class Laborer   : public Employee

/*. NOTE:
std::cin reads till \n 
In the buffer the \n is still present, so if std::cin.getline() is called, it consumes the \n and returns a empty string
Thus use std::cin.ignore()

!! Whenever working with char arrays[] use std::cin.getline() as it reads whitespaces and \n.

std::string school;
std::getline(std::cin, school);  // user types: ABC High School
std::cout << school;             // outputs: ABC High School

std::string name;
std::cin >> name;  // user types: John Doe
std::cout << name; // outputs: John  (only the first word)

*/

#include<iostream>

const int LEN = 80;

class Student
{
    private:
    char school[LEN];
    char degree[LEN];

    public:
    void getedu()
    {
        std::cout << "enter school: "; 
        std::cin.ignore(); // to empty the buffer, remove \n
        std::cin.getline(school, LEN);

        std::cout << "enter degree: "; 
        std::cin.getline(degree,LEN);
    }

    void putedu()
    {
        std::cout << "school: " << school << std::endl
                  << "degree: " << degree << std::endl;
    }
};


class Employee
{
    private:
    char name[LEN];
    unsigned long number;

    public:
    void getdata()
    {
        std::cout << "enter name: "; 
        std::cin.ignore();
        std::cin.getline(name, LEN);


        std::cout << "enter number: "; 
        std::cin >> number;
    }

    void putdata()
    {
        std::cout << "Name: "<< name << std:: endl
                  << "Number: " << number << std::endl; 
    }

};


class Manager : public Employee, public Student
{
    private:
    char title[LEN];
    double dues;

    public:
    void getdata()
    {
        Employee::getdata();
       
        std::cout << "enter title: "; 
        std::cin.ignore();
        std::cin.getline(title,LEN);
        
        std::cout << "enter dues: "; 
        std::cin >> dues;
        
        Student :: getedu();
    }

    void putdata()
    {
        Employee::putdata();
    
        std::cout << "Title: " << title << std::endl
                  << "Dues: " << dues << std::endl;

        Student :: putedu();
    }
};


class Scientist : public Employee, public Student
{
    private:
    int pubs;

    public:
    void getdata()
    {
        Employee :: getdata();
      
        std::cout << "enter pubs: "; std::cin >> pubs;

        Student :: getedu();

    }

    void putdata()
    {
        Employee :: putdata();
       
        std::cout << "Pubs: " << pubs << std::endl;

        Student :: putedu();
    }
};



class Laborer : public Employee
{

};





// --- MAIN ---
int main()
{
    Manager m1;
    Scientist s1;
    Laborer l1;
    //Student ss1;

    //std::cout << "enter data for student " << std::endl;
    //ss1.getedu();

    std::cout << "enter data for manager " << std::endl;
    m1.getdata();

    std::cout << "enter data for scientist" << std::endl;
    s1.getdata();

    std::cout << "enter data for laborer" << std::endl;
    l1.getdata();

  
    // display
    std::cout <<"Data entered" << std::endl;
    //ss1.putedu();
    m1.putdata();
    s1.putdata();
    l1.putdata();
   


    std::cout << std::endl;

}


