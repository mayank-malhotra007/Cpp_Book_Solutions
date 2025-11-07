/*
    employ.cpp: showcases public inheritance with invokation of base class function using scope resolution
*/

#include<iostream>

const int LEN = 80;

class Employee
{
    private:
    char name[LEN];
    unsigned long number;

    public:
    void getdata()
    {
        std::cout << "enter name: "; std::cin >> name;
        std::cout << "enter number: "; std::cin >> number;
    }

    void putdata()
    {
        std::cout << "Name: "<< name << std:: endl
                  << "Number: " << number << std::endl; 
    }

};


class Manager : public Employee
{
    private:
    char title[LEN];
    double dues;

    public:
    void getdata()
    {
        Employee::getdata();
        std::cout << "enter title: "; std::cin >> title;
        std::cout << "enter dues: "; std::cin >> dues;
    }

    void putdata()
    {
        Employee::putdata();
        std::cout << "Title: " << title << std::endl
                  << "Dues: " << dues << std::endl;
    }
};


class Scientist : public Employee
{
    private:
    int pubs;

    public:
    void getdata()
    {
        Employee :: getdata();
        std::cout << "enter pubs: "; std::cin >> pubs;

    }

    void putdata()
    {
        Employee :: putdata();
        std::cout << "Pubs: " << pubs << std::endl;
    }
};



class Laborer : public Employee
{

};


class Foreman : public Laborer
{
    private:
    int quotas;

    public:
    void getdata()
    {
        Employee :: getdata();
        std::cout << "enter quotas: "; std::cin >> quotas;

    }

    void putdata()
    {
        Employee :: putdata();
        std::cout << "quotas: " << quotas << std::endl;
    }
};




// --- MAIN ---
int main()
{
    Manager m1;
    Scientist s1;
    Laborer l1;
    Foreman f1;

    std::cout << "enter data for manager " << std::endl;
    m1.getdata();

    std::cout << "enter data for scientist" << std::endl;
    s1.getdata();

    std::cout << "enter data for laborer" << std::endl;
    l1.getdata();

    std::cout << "enter data for forman" << std::endl;
    f1.getdata();

    // display
    std::cout <<"Data entered" << std::endl;
    m1.putdata();
    s1.putdata();
    l1.putdata();
    f1.putdata();


    std::cout << std::endl;

}

