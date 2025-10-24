/* light On Off state machine */


#include<iostream>

void Off();
void On();

int main()
{
  std::cout << "In state OFF" << std::endl;
  int c;
  
  do{

    std::cout << "Enter [1:ON, 2:OFF, 0:Exit] ";
    std::cin>>c;

    switch(c)
    {
        case 1 : On(); break;
        case 2 : Off(); break;
        case 0 : std::cout << "exiting..." << std::endl; break;
        default : std::cout << "wrong choice, enter again"<<std::endl;
    }

  }while(c!=0);

  return 0;
}

void On()
{
    std::cout << "entered state On"<< std::endl;
    
}


void Off()
{
    std::cout << "entered state Off"<< std::endl;
}