/* stack as an array */

#include<iostream>
#define MAX 5

class Stack
{

    int st[MAX];
    int top;
    public:
    Stack(){top=-1;}

    void pushItem(int d)
    {
        if(top==MAX)
        {   
            std::cout<<"stack full"<<std::endl;
            return;
        }
        else
        {
            ++top;
            st[top]=d;
            std::cout<<"item pushed on stack"<<std::endl;

        }
        
    }
    void popItem()
    {
        if(top==-1)
        {
            std::cout<<"stack empty"<<std::endl;
            return;
        }
        else
        {
            int x = st[top];
            top--;
            std::cout<<"popped"<<x<<std::endl;
        }
    }

};


int main()
{
 Stack s1;
 s1.pushItem(10);
 s1.pushItem(20);
 s1.popItem();
 return 0;
}