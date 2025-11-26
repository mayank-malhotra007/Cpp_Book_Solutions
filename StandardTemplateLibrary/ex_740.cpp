

#include<iostream>
#include<algorithm>

void sort_desc(const char* [] , int);


int main()
{

 // array of pointers to strings
 const char* names[] = {"cara", "bob", "adele"};

 for(auto x:names)
 {  
     std::cout << x << " ";
 }

 std::cout << std::endl;
 std::cout << "after sorting" << std::endl;

 std::sort(names, names+3, [](const char* a, const char* b){
        return  (strcmp(a,b)<0); 
         }   );

 for(auto y : names)
 {
    std::cout << y << " ";
 }
 
 sort_desc(names,3);


 for(auto z : names)
 {
    std::cout << z << " ";
 }


 return 0;
}


void sort_desc(const char* ptr[], int len)
{
    std::sort(ptr, ptr+len , [](const char* s1, const char* s2){return(strcmp(s1,s2)>0);});
}



