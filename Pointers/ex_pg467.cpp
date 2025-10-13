/* array of pointers to object */

#include<iostream>

// -- person --
class Person
{
    char name[16];
    public:
        void setName(){
            std::cout<<"enter name: ";
            std::cin>>name;
        }

        void getName(){
            std::cout<<"Name: "<<name<<std::endl;
        }

      ~Person()
      {
        static int count=0;
        std::cout<<"destructor called "<<count<<std::endl;
        count++;
      }

};

// ----- MAIN -----
int main()
{
  Person* person[5]; // array of pointers to class Person
  int n=0;
  char ch;

  do
  {
    person[n] = new Person; // dynamic assign the memory
    person[n]->setName();
    n++;
    std::cout<<"enter one more? y/n: ";
    std::cin>>ch;
    
  }while(ch == 'y' || ch == 'Y');

  //-- print the entries --

  for(int i=0; i<n; i++)
  {
    person[i]->getName();
  }

  // release memory 
  for(int j=0; j<n; j++)
  {
   delete person[j];
   std::cout<<"deleted"<<std::endl;
   person[j] = nullptr;
  }

 return 0;
}