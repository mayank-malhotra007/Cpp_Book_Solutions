/* stack from an array */

#include<iostream>
#define MAX 5

class Stack
{
    
    int top;
    int v[MAX];

    public:
    
    Stack(){top=-1;}

    // -- push --
    void push(int d)
    {
        if(top==MAX-1)
        {
            std::cout<<"stack full"<<std::endl;
            return;
        }
        else
        {
            ++top;
            v[top] = d;
            std::cout<<"element "<<d<<" pushed"<<std::endl;
        }
    }

    // -- pop --
    void pop()
    {
        if(top==-1)
        {
            std::cout<<"stack is empty"<<std::endl;
            return;
        }
        else
        {
            int x = v[top];
            top--;
            std::cout<<"element "<<x<<" popped"<<std::endl;
        }
    }

    int peek()
    {
        if(top==MAX-1)
        {
            std::cout<<"stack is full";
            return -1;
            
        }
        std::cout<<v[top]<<std::endl;
        return 0;
    }

};


// -- MAIN --
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();
    s.peek();

    return 0;
}