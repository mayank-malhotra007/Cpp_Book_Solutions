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
        std::cout << "enter name: "; 
        std::cin.getline(name, LEN); 
        
        std::cout << "enter number: "; 
        std::cin >> number;

        std::cin.ignore();
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
       
        std::cout << "enter title: "; 
        std::cin.getline(title, LEN); 

        std::cout << "enter dues: "; 
        std::cin >> dues;
        std::cin.ignore();
    }

    void putdata()
    {
        std::cout << "Title: " << title << std::endl
                  << "Dues: " << dues << std::endl;
    }
};



class Executive : public Manager
{
    int bonus;
    int shares;

    public:
    void getdata()
    {
        Employee :: getdata();
        Manager :: getdata();

        std::cout << "enter bonus: "; 
        std::cin >> bonus;
        std::cin.ignore();
        
        std::cout << "shares: "; 
        std::cin >>shares;
        std::cin.ignore();
    }


    void putdata()
    {
        Employee :: putdata();
        Manager :: putdata();
        std::cout << "shares: " << shares << std::endl  
                  << "bonues: " << bonus << std::endl;
    }

};


// --- MAIN ---
int main()
{
   
    Executive e1;

    e1.getdata();
    e1.putdata();

    std::cout << std::endl;

    return 0;

}

