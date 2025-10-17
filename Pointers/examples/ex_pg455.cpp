/* copy a string using pointers */

#include<iostream>
#include<string>

void copyString(char* , int);
void concatenateString(char[] , char[]);
void concatenate(char [], char []);

int main()
{
    std::string str1 = "abcd";
    char str2[5];

    // using the copy() method of std::string
    str1.copy(str2,sizeof(str2));
    std::cout<<str2;
    std::cout<<std::endl;

    // using strcpy , for C strings
    char arr1[] = "xyz";
    int len = sizeof(arr1);
    char arr2[len];

    strcpy(arr2,arr1);
    std::cout<<arr2<<std::endl;
    std::cout<<sizeof(arr2);


    // string copy using pointers
    char* ptr;
    ptr = arr1;
    copyString(ptr, len);

    //contenate 2 strings
    concatenateString(arr1,arr2);
    concatenate(arr1,arr2);

    return 0;
}

// -- COPY STRING --
void copyString(char* p, int len)
{
    std::string line;
    for(int i=0; i<len; i++)
    {
        char ch=*(p+i );
        line+=ch;
    }
    std::cout<<std::endl;
    std::cout<<"copied string is "<<line<<std::endl;
}

// -- CONCATENATE using strcat --
void concatenateString(char s1[] , char s2[])
{
   std::cout<<"s1: "<<s1<<std::endl;
   std::cout<<"s2: "<<s2<<std::endl;

   char s3 [20];
   strcat(s3,s1);
   strcat(s3, " ");
   strcat(s3,s2);
   

   std::cout<<"s3: "<<s3<<std::endl;
}

// --CONTENATE using strncat --
void concatenate(char s1[], char s2[])
{
    char s4[20] = "";
    strncat(s4,s1,2);
    strcat(s4, " ");
    strncat(s4,s2,1);
   
    std::cout<<"s4: "<<s4<<std::endl;
    
}