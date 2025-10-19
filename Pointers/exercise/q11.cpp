
#include<iostream>


class Arr
{
    int num;
    int size;
    int** pp;

    public:
        Arr(int n,int s,int** p): num(n), size(s), pp(p) {std::cout<<"initialized"<<std::endl;}

        int operator[](int index) {
            int row =index/size;
            int col =index%size;

            // pp[row] returns address or a pointer to the first element of each array
            // pp[row][col] returns the element
            return pp[row][col];
        }


        void display();
    

        ~Arr()
        {
            std::cout<<"destructor called"<<std::endl;
            for(int x=0; x<num; x++)
            {
                delete[] pp[x];
            }
        }
};



void Arr :: display()
{
    for(int x=0; x<num*size; x++)
    {
        //std::cout<< operator[](x);
        // or
        // this is a pointer to the current class object, *this is that object itself in our case a1
        std::cout<< (*this)[x];  
        std::cout<<std::endl;
    }
}


// --- MAIN ---
int main()
{
    const int num_arrays = 5;
    const int size_array= 5;
    static int count;

    // array of pointers
    int* ptr_array[num_arrays];

    // allocate memory to pointers
    for(int x=0; x<num_arrays; x++)
    {
        ptr_array[x] = new int[size_array];
    }

    // fillin the arrays
    for(int x=0; x<num_arrays; x++)
    {
    
        for(int y=0; y<size_array; y++)
        {
                   
            // fill the arrays
            ptr_array[x][y] = count;
            count++;
        }
    }

    // create a class object
    Arr a1(num_arrays, size_array, ptr_array);
    a1.display();


    
    


    return 0;
}