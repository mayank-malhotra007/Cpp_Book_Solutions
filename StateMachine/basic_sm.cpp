
/* simple state machine */

#include<iostream>
#include<chrono>
#include<thread>

char def();
void stateA();
void stateB();

int main()
{
    int c;
    do{
    c = def();
    switch(c)
    {
        case 1 : stateA(); break;
        case 2 : stateB(); break;
        case 0 : std::cout << "exiting.." << std::endl;break;
        default  : std::cout << "entered wrong choice" << std::endl; break;
 
    }
    }while(c!=0);
    
 return 0;
}

char def()
{

 int ch;
 std::cout << "entered state default" << std::endl;
 std::cout << "enter choice (1:A, 2:B, 0:Exit): ";
 std::cin >> ch;

 return ch;

}



void stateA()
{
 
    std::cout << "entered state A" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5)); // pauses for 5 seconds
    std::cout << "calling state B, exiting state A..." << std::endl;
    stateB(); 
    
}


void stateB()
{
 
    std::cout << "entered state B" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5)); // pauses for 5 seconds
    std::cout << "calling state default, exiting state B..." << std::endl;

}