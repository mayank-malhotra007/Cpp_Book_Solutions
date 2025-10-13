/* string class and new */

#include<iostream>

// -- STRING --
class String{

    char* ptr;
    
    public:
        
        String(const char* str) 
        {
            std::cout<<"first constructor called"<<std::endl;
            int len = strlen(str);
        
            // assign memory
            ptr = new char[len+1];
            strcpy(ptr,str); // copy the string to the pointer
        }

        String(char c) {
            std::cout<<"second constructor called"<<std::endl;
            ptr = new char[2];
            ptr[0] = c;
            ptr[1] = '\0';
        }

    void display(){
        std::cout<<ptr<<std::endl;
        ptr = nullptr;
    }

    ~String(){
        static int count;
        count ++;
        std::cout<<"calling destructor"<<count<<std::endl;
        delete [] ptr;
    }

};


// -- MAIN --
int main(){
 
 const char* str = "Hello World!";
 char ss[]  = "Today is a good day!"; // also reduces to const char*
 char ch = 'M';

 String s1(str); // pass a pointer to a string
 String s2(ss);  // pass the string as a reference
 String s3(ch); 

 
 s1.display();
 s2.display();
 s3.display();

 return 0;
}