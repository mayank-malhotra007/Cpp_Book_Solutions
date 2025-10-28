/*   Compare char[] lexicographically using their ASCII values char by char  */
/*
 When a return statement is executed inside a function:
 The function immediately stops running.
 The remaining code in that function is skipped.
 Control returns to the calling function (for example, main() in your case).
 The value after return (if any) is given back to the caller.
*/

#include<iostream>
#include<string>
#include<cstring>


class String
{
    char str[50];

    public:
    String(char s[])
    {
        strcpy(str,s);
    }

    void display()
    {
        std::cout << str << std::endl;
    }

    int operator==(String& rhs)
    {
        int len_str1 = strlen(str);
        int len_str2 = strlen(rhs.str);
        int len;
        int status = 0;

        char ch1, ch2;

        if(len_str1 < len_str2)
        {
            std::cout << "string length is unequal" << std::endl;
            len = len_str1;
        }
        else if (len_str1 > len_str2)
        {
            std::cout << "string length is unequal" << std::endl;
            len = len_str2;
            
        }
        else
        {
            std::cout << "string length is equal" << std::endl;
            len = len_str1;
        }

        //comparison
        for(int i=0; i<len; i++)
        {
            ch1 = str[i];
            ch2 = rhs.str[i];

            if(ch1 < ch2)
            {
                status = -1;
                return status;
            }
            else if (ch1 > ch2)
            {   
                status = 1;
                return status;
            }
            else
            {
                continue;
            }
         
        }// for ends

        // here status=0 is returned, since no if or else if executed
        return status;
    
    }//operator ends


};



int main()
{
  char str1[] = "ac";
  char str2[] = "ac";

  String s1(str1);
  String s2(str2);

  if((s1==s2) == 0)
  {
    std::cout << "strings are equal" << std::endl;
  }
  else if((s1==s2)==1)
  {
    std::cout << str1 << " comes after " << str2 << std::endl;
  }
  else if ((s1==s2)==-1)
  {
    std::cout << str1 << " comes before " << str2 << std::endl;
  }
  else
  {
    std::cout << "wrong status returned" << std::endl;
  }

 return 0;
}