
/*
    Use of std::cin.getline() and std::getline() for char arrays and std::string
*/


#include<iostream>

int main()
{
 std::string name;

 char surname[10];

 std::cout <<"enter name: ";
 std::getline(std::cin,name);

 std::cout << "enter surname: ";
 std::cin.getline(surname,10);

 std::cout << std::endl;
 std::cout << name << " " << surname << std::endl;

 return 0;
}