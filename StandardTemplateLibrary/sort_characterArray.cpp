

#include<iostream>

void sort_char(char arr[], int );

int main()
{

 char name[] = "dcba";

 std::cout << name << std::endl;

 sort_char(name, strlen(name));

 std::cout << name << std::endl;

 return 0;
}


void sort_char(char arr[], int len)
{
    char temp = '\0';
    for(int x=0; x<len-1; x++)
    {
        for(int y=x+1; y<len; y++)
        {
            if(arr[x]>arr[y])
            {
                temp = arr[x];
                arr[x] = arr[y];
                arr[y] = temp;
            }
        }
    }

}
