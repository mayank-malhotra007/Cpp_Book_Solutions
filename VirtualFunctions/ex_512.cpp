
#include<iostream>


class Person
{

    protected:
     char name[40];

    public:
     void getName()
     {
        std::cout << "enter name:";
        std::cin>>name;
     }


     void putName()
     {
      std::cout << name << std::endl;  
     }

     virtual void getData() = 0;
     virtual bool isOutstanding() = 0;

};


class Student : public Person
{
    private:
        float gpa;
    public:
        void getData()
        {
            getName();
            std::cout << "enter gpa: ";
            std::cin >> gpa;
    
        }

        bool isOutstanding()
        {
            return (gpa > 3.5 ? true : false);
        }

};


class Professor : public Person
{
    private:
        int numPubs;
    
    public:
        void getData()
        {
            getName();
            std::cout << "enter num of publications: ";
            std::cin >> numPubs;
        }

        bool isOutstanding()
        {
            return(numPubs > 100 ? true : false);
        }

};


// --- MAIN ---
int main()
{

 /*
 Person* ptr1 = new Student();
 Person* ptr2 = new Professor();
 ptr1->getData();
 ptr2->getData();
 */

 //std::cout <<"result gpa greater that 3.5: " << ptr1->isOutstanding() << std::endl;
 //std::cout <<"result number of pubs greater than 100: " << ptr2->isOutstanding() << std::endl;


 int n = 0;
 Person* ptr[100];

 char ch;
 int choice = 0;

  do
  {
    std :: cout << "enter 1 for student and 2 for professor: ";
    std::cin >> choice;
    if(choice == 1)
    {
        ptr[n] = new Student();
        ptr[n] -> getData();
        n++;
    }
    else if(choice == 2)
    {
        ptr[n] = new Professor();
        ptr[n] -> getData();
        n++;
    }
    else
    {
        std::cout << "wrong choice, enter again" << std::endl;
    }

    std::cout << "enter a new entry? Y/N: ";
    std::cin >> ch;

}while(ch =='y' || ch == 'Y');

 // display 
 for(int x=0; x<n; x++)
 {
    ptr[x]->putName();
    if(ptr[x]->isOutstanding())
    {
        std::cout << "is outstanding " << std::endl;
    }
 }

 return 0;
}