/* pointers to pointers */

#include<iostream>
#include<string>



class Person
 {

    protected:
        std::string name;

    public:
        void setName()
        {
            std::cout<<"enter name: ";
            std::cin>>name;
        }

        void printName()
        {
            std::cout<<name<<std::endl;
        }

        std::string getName()
        {
            return name;
        }

 };

void bsort(Person** ,int );

int main()
{


    Person* persPtr[100]; //array of 100 pointers to class Person objects
    int n=0;
    char choice;

    do
    {
        persPtr[n] = new Person; // mem allocated to pointer
        persPtr[n]->setName();
        n++;
        std::cout<<"enter another? Y/N";
        std::cin>>choice;
    }while(choice=='Y' || choice=='y');

    //display unsorted
    for(int x=0; x<n; x++)
    {
        persPtr[x]->printName();
    }
    
    // call the sort program
    bsort(persPtr, n);

    //display sorted 
     for(int x=0; x<n; x++)
    {
        persPtr[x]->printName();
    }

    return 0;
}

// bubble sort program
void bsort(Person** pp, int n) // **pp points to an array of pointers
{
  void order(Person** , Person** );
  int j,k;
  
  for(int j=0; j<n; j++)
  {
    for(k=j+1; k<n; k++)
    {
        order(pp+j,pp+k);
    }
  }
}


void order(Person** pp1,Person** pp2)
{
    if( (*pp1)->getName()> (*pp2)->getName()  )
    {
        Person* temp;
        temp = *pp1;
        *pp1 = *pp2;
        *pp2 = temp;
    }
}