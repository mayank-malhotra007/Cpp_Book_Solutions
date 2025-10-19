
#include<iostream>

void display(int**,int,int);
void fill(int**, int, int);

int main()
{
 const int num_arrays=10;
 const int SIZE = 5;
 int *ptr[num_arrays];

 // -- create 10 arrays each of size 5, allocate a pointer to each one of them
 for(int x=0; x<10; x++)
 {
   ptr[x] = new int[SIZE];
   // *(ptr+x) = new int[SIZE];
 }

 // fill the created arrays
 fill(ptr,SIZE,num_arrays);


 // -- display the created arrays
 display(ptr, num_arrays, SIZE);


 return 0;
}


// -- display --
void display(int** p, int num,int size)
{
    // access each ptr to the 10 arrays, so 10 pointers, 10 addresses
    for(int x=0; x<num;x++)
    {
        //std::cout<<(p+x)<<" "<<*(p+x)<<" "<<**(p+x)<<std::endl;
        for(int y=0; y<size; y++)
        {
            std::cout<<p[x][y]<<" ";
        }
        std::cout<<std::endl;
    }
}


// -- fill in the arrays --
void fill(int** p, int size, int num_arrays)
{
 static int count;
 for(int x=0; x<num_arrays; x++)
 {
    for(int y=0; y<size; y++)
    {
        p[x][y] = count;
        count++;
    }
 }    

}

