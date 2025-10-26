/* clarray.cpp */

#include<iostream>


class Array
{
    int* ptr;
    int size;

    public:
        Array(): size(0), ptr(nullptr){}

        Array(int s)
        {
            size = s;
            ptr = new int[s];
        }

        //copy constructor
        Array(const Array& rhs)
        {
            std::cout << "copy constructor called" << std::endl;
            size = rhs.size;
            ptr = new int[size]; // new mem allocated to pointer of arr2, new array created

            for(int i=0; i<size; i++)
            {
                ptr[i] = rhs.ptr[i];
            }
            
        }

        //copy assignment
        Array& operator=(const Array& rhs)
        {
            /*
             1. check for self assignment
             2. free old memory
             3. allocate new memory
             4. copy contents
            */

            // check self assignment
            if(this == &rhs)
            {
                return *this;
            }
            
            delete[] ptr; //free old memory of arr3 object not arr which is the source

            std::cout << "copy assignment called" << std::endl;
            size = rhs.size;
            ptr =  new int[size]; // new mem allocated to pointer of arr3, new array created

            //NOTE: do not do: ptr = rhs.ptr, then both pointers point to same array!

            for(int i=0; i<size; i++)
            {
                ptr[i] = rhs.ptr[i];
            }

            return *this;
        }



        ~Array()
        {
            
            std::cout << "destructor called" << std::endl;
            delete[] ptr;
        }

        //overloading the []operator
        int& operator[](int j)
        {
            return *(ptr+j);
        }
};


int main()
{
 const int ASIZE = 10;
 Array arr(ASIZE); // constructor called
 

 for(int j=0; j<ASIZE; j++)
 {
    arr[j] = j*j;
 }

 Array arr2(arr); // copy constructor invoke

 Array arr3;
 arr3 = arr; // copy assignment invoked

 //display arr
 for(int x=0; x<ASIZE; x++)
 {
    std::cout << arr[x] << " ";
 }

 std::cout << std::endl;


 //display arr2
for(int y=0; y<ASIZE; y++)
{
    std::cout << arr2[y] << " ";
}


 std::cout << std::endl;

//display arr3
for(int z=0; z<20; z++)
{
    std::cout << arr3[ASIZE] << " ";
    
}

 std::cout << std::endl;
 return 0;
}
