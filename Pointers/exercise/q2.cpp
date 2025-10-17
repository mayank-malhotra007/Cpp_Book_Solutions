
#include<iostream>
#include<string>
#include<cstring>


class String
{
 const char* str;
 int len;

 public:
    String(const char* s)
    {
         str = s;
         //std::cout<<str<<std::endl;
         len = strlen(str);
         //std::cout<<"length: "<<len<<std::endl;
    }

    std::string upit()
    {
        //const char* ptr;
        //ptr = str;
        std::string line;
        for(int x=0; x<len; x++)
        {
            //std::cout<< *(ptr+x);
            char ch;
            ch = *(str+x);
            //std::cout<<ch;
            line+=std::toupper(ch);

        }
        //std::cout<<"line: "<<line<<std::endl;
        return line;
    }

    void testUpperCase(std::string);

};

// -- test case --
void String :: testUpperCase(std::string st)
{
  int count = 0;
  int l = st.size();
  
  const char* ptr = st.c_str(); // gets a pointer to first char in string, cant modify const
  // OR
  //char* ptr = &st[0];  // gets a pointer to first char in string, does not return null terminated string, can modify

  // while(ptr!='\0') when using c_str()
  // OR
  for(int x=0; x<l; x++)
  {
    char ch = *(ptr+x);
    if(std::isupper(ch))
    {
        count++;

        
    }

    if(ch==' ')
    {
        count++;
    }
    //std::cout<<"count: "<<count<<std::endl;
    //std::cout<<"length: "<<l << std::endl;


    if(count==l)
    {
        std::cout<<"all characters are upper case"<<std::endl;
    }

  }
}


// -- MAIN --
int main()
{
 char s1[] = "Hello World";
 String s(s1); 

 std::string result;
 
 // convert to uppercase
 result=s.upit();

 // print
 std::cout<<result;

 // check uppercase
 s.testUpperCase(result);


 return 0;
}