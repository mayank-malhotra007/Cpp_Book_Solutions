/* array of pointers */
/*     note in C++ strings reduce to type [const char*] not [char*]     */

#include<iostream>
#include<string>

int main()
{
 // array of pointers to string
 const char* DAYS[] = {"Mon", "Tue", "Wed"}; 
   
 for(int i=0; i<3; i++)
 {
    std::cout<<DAYS[i]<<" ";
 }

 // pointer to an entire array of n characters
 char name[10] = "Expleo";
 char (*D)[10];
 D = &name;

 std::cout<<std::endl;
 std::cout<<"D:"<<*D;

 // pointer to a char because addr reduces to addr[0]
 char addr[20] = "Munich at 123";
 char* p;
 p = addr;

 std::cout<<std::endl;
 std::cout<<"p: "<<p<<std::endl;

 /* std::cout overloads the ostream , and that fuction returns entire string and not the first char*/

 //gives access to each character
 for(int i=0; i<strlen(addr); i++)
 {
    char c = *(p+i);
    std::cout<<c;
 }

 return 0;
}
