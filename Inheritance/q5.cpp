
#include<iostream>



// # define LEN 20


class Employee
{
    private:
    static const int LEN = 20;
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


class Employee2 : public Employee
{
    double compensation;
    enum period {hourly, weekly, monthly};
    int x;

    public:

    void getdata()
    {
        Employee :: getdata();
        std::cout << "enter compensation: "; std::cin >> compensation;
        std::cout << "enter period [0:hourly, 1: weekly, 2:monthly]"; std::cin >> x;
        std::cin.ignore();
    }

    void putdata()
    {
        Employee :: putdata();
        std::cout << compensation << std::endl;
        switch(x)
        {
            case 0 : std::cout << "hourly" ; break;
            case 1 : std::cout << "weekly" ; break;
            case 2 : std::cout << "monthly" ; break;
            default : std::cout << "wrong choice"; break;
        }    
    }

};


// -- MAIN --
int main()
{
  Employee2 emp1;
  
  emp1.getdata();
  emp1.putdata();


 return 0;
}