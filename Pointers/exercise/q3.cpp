/* sorting using pointers to pointers */

#include<iostream>

void sort(const char** , int);
void order(const char** , const char** );

int main()
{

 /* note: here 7 pointers are created each pointing to the address of first character of the days of week */   
 /* note: each elemt of this ptr_arr is of the type const char*                                          */

 const char* ptr_arr[] = {"Sunday", "Tuesday", "Thursday", "Wednesday", "Friday", "Saturday", "Monday"};
 
 std::cout<<"------- Before Sorting -------"<<std::endl;

 for(const char* x: ptr_arr)
 {
    // ostream << overloads so it prints the strings and not the addresses!
    std::cout<<x<<" ";
    // to print the addresses
    std::cout<<static_cast<const void*>(x)<<std::endl;
    
 }

 /*    ptr_arr reduces to const char**     */
 //sort(ptr_arr, 7);
 sort(&ptr_arr[0],7);
 std::cout<<std::endl;

 std::cout<<"after sorting"<<std::endl;
 for(const char* x: ptr_arr)
 {
    std::cout<<x<<" ";
 }
 
 
 return 0;
}


void sort(const char** p, int len)
{
 //std::cout<<std::endl;
 //std::cout<<*p;

 for(int i=0; i<len-1; i++)
 {
    //std::cout<<*(p+i)<<" ";
    for(int j=i+1; j<len; j++)
    {
       order((p+i),(p+j));  // pass the pointers to the order function which does the ordering
    }
 }

    // print the sorted array

    /*
    std::cout << "\n------- Sorted Inside sort() -------\n";
    for(int i = 0; i < len; i++)
    {
        std::cout << *(p+i) << " ";
    }
    */

}


void order(const char** pp1, const char** pp2)
{
   //std::cout<<*pp1<<std::endl;
   //std::cout<<*pp2<<std::endl;

   // - use strcmp() to sort -
   if(strcmp(*pp1,*pp2)>0)
   {
     const char* temp = *pp1;
     *pp1 = *pp2;
     *pp2 = temp;
   }

  
}