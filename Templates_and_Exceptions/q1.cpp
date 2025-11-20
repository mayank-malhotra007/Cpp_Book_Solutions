
#include<iostream>


template<typename T>
T calculate_avg(T name[], int size)
{
    auto temp = 0;
    for(int x=0; x<size; x++)
    {
        temp+=name[x];
    }

    auto avg = temp/size;
    return avg;
}


// --- MAIN ---
int main()
{
 const int SIZE = 5;
 int number[SIZE];
 float number2[SIZE];
 double number3[SIZE];
 long number4[SIZE];

 // fill in the array
 for(int i=0; i<SIZE; i++)
 {
    std::cout<<"enter " << i << "th " <<" element: ";
    std::cin >> number3[i];
 }

 //pass the array to avg function
 auto result = calculate_avg(number3, SIZE);
 std::cout << "avg is: " << result << std::endl;

 return 0;
}