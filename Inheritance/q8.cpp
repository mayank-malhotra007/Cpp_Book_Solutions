/*
 String extended with substring
*/

#include<iostream>
#include<cstring>
#include<string>

const int SIZE = 20;


class String
{
    protected:
    char str[20];

    public:
    String() {
        strcpy(str , "");
    }

    String(const char ss[]) 
    {
        strcpy(str, ss);
    }

    void display()
    {
        std::cout << str << std::endl;
    }

    const char* get_string()
    {
        return str;
    }

    void enter_string()
    {
        std::cout << "enter string"; std::cin.getline(str,20);
    }

};


class Pstring : public String
{
    char substr[SIZE];

    public:
    Pstring() : String(){}
    Pstring(const char s[]) : String( std::string(s).substr(0,2).c_str() ) 
    {
        strcpy(substr, s);
    }

    void display()
    {
        String :: display();
        std::cout << substr << std::endl;
    }

    void append_right()
    {
        strcat(substr, " ");
        strcat(substr, String::get_string());
    }


    void append_left()
    {
        char temp[SIZE];
        strcpy(temp, String::get_string());

        strcat(temp, " ");
        strcat(temp, substr);
        strcpy(substr,temp);
    }

    // 1st method
    void append_middle(int i)
    {
        char temp[SIZE];
        char yemp[SIZE];

        temp[0] = '\0';
        yemp[0] = '\0';

        int len = strlen(substr);
        
        //check index out of range
        if(i < 0 || i >len)
        {
            std::cout << "invalid index" << std::endl;
        }

        //left part
        for(int x=0; x<i; x++)
        {
            temp[x]=substr[x];
            
        }
        temp[i] = '\0'; // C strings have to be null terminated

        //right part
        for(int x=i, j=0 ; x<len; x++,j++)
        {
            yemp[j] = substr[x];
        }
        yemp[len-i] = '\0';

        strcat(temp, " ");
        strcat(temp, String::get_string());
        strcat(temp, " ");
        strcat(temp, yemp);

        //copy to substr
        strcpy(substr, temp);



    }

    // 2nd method
    void middle(int i)
    {
        std::string left(substr,i); // get left part from index
        std::string right(substr + i); // get right part from index
        
        std::cout << "left: " << left << std::endl;
        std::cout << "right: " << right << std::endl;

        std::string result = left + " " + String::get_string() + " " + right;

        strncpy(substr, result.c_str(), SIZE-1);
        substr[SIZE-1] = '\0';
    }

};


// -- MAIN --
int main()
{

    Pstring p2("hello world");

    p2.display();

    //p2.append_right();
    //p2.display();

    //p2.append_left();
    //p2.display();

    // -- append in middle --
    int index;
    std::cout << "enter index to append to: ";
    std::cin >> index;

    //p2.append_middle(index);
    
    p2.middle(index);
    p2.display();




    return 0;
}