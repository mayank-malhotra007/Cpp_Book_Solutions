/*    implementing our own strcmp()  */

#include<iostream>

int comp(const char*, const char*, int, int);



int main()
{
    const char* s1 = "XYZ";
    const char* s2 = "XAYZ";

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    //std::cout<<len1<<" "<<len2<<std::endl;

    int result = comp(s1,s2,len1,len2);

    if(result<0)
    {
        std::cout<<"string "<<s1<<" comes before "<<s2<<std::endl;

    }
    else if(result>0)
    {
        std::cout<<"string "<<s2<<" comes before "<<s1<<std::endl;
    }
    else
    {
        std::cout<<"strings are the same"<<std::endl;
    }

    return 0;
}


// -- compare --
int comp(const char* s1, const char* s2, int len1, int len2)
{
    int flag=0;
    if(len1<len2)
    {
        for(int x=0; x<len1; x++)
        {
            char ch1, ch2;
            ch1 = *(s1+x);
            ch2 = *(s2+x);
            
            if(ch1<ch2)
            {
                flag = -1;
                break;
            }
            else if(ch1>ch2)
            {
                flag = 1;
                break;
            }
            else
            {
                flag = 0;
                continue;
            }

        }

        
    }
    else if(len1>len2) 
    {
        for(int y=0; y<len2; y++)
        {
            char ch1, ch2;
            ch1 = *(s1+y);
            ch2 = *(s2+y);
            
            if(ch1<ch2)
            {
                flag = -1;
                break;
            }
            else if(ch1>ch2)
            {
                flag = 1;
                break;
            }
            else
            { 
                flag = 0;
                continue;
            }
        }
    }
    else
    {
        for(int y=0; y<len2; y++)
        {
            char ch1, ch2;
            ch1 = *(s1+y);
            ch2 = *(s2+y);
            
            if(ch1<ch2)
            {
                flag = -1;
                break;
            }
            else if(ch1>ch2)
            {
                flag = 1;
                break;
            }
            else
            {
                flag=0;
                continue;
            }
        }
    }

    if(flag<0) return -1;
    else if(flag>0) return 1;
    else return 0;

}