
/* A unique pointer is a smart pointer that owns and manages an object , this object cannot be shared 
   Unique ownership of the object,
   Copy of object cannot be created,
   Object can be moved
*/

#include<iostream>

int main()
{
 
 static int count;
 std::unique_ptr<int[]> ptr= std::make_unique<int[]>(5); // this allocates the memory, like new or malloc

 /* ptr is a smart pointer that points to an array of 5 ints */
 for(int x=0; x<5; x++)
 {
    ptr[x] = count++;
 }

 
 // display
 for(int i=0; i<5; i++)
 {
    std::cout<<ptr[i]<<" ";
 }
 
 std::cout<<std::endl;
 return 0;

}