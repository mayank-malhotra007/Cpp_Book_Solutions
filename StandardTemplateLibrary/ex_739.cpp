
#include<iostream>
#include<algorithm>
#include<functional>


void sort_characters(const char* ptr, const int len)
{


    for(int x=0; x<len; x++)
    {
        std::cout << ptr(x);
    }

}




int main()
{


 double fdata[] = {19.2, 87.4, 33.6, 55.0, 11.5, 42.2};
 
 std::sort(fdata, fdata+6, std::greater<double>());

 // - display
 
for(int x=0; x<6; x++)
 {
    std::cout << fdata[x] << " " << std::endl;
 }



 return 0;
}
