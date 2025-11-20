/*
    Multiple exceptions
*/


#include<iostream>
const int MAX = 3;

class Stack
{
    int st[MAX];
    int top;

    public:
    class Full {};
    class Empty {};

    Stack()
    {
        top = -1;
    }
    void push(int d)
    {
        if(top >=MAX-1)
        {
            throw Full();
        }
        else
        {
            st[++top] = d;
        }
    }

    int pop()
    {
        if(top<0)
        {
            throw Empty();
        }
        else
        {
            return st[top--];
        }
    }
};


// ---
int main()
{
    Stack s1;

    try
    {
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.push(4);
    }catch(Stack::Full)
    {
        std::cout << "stack is full " << std::endl;
    }

    try
    {
        s1.pop();
        s1.pop();
        s1.pop();
        s1.pop();
    }catch(Stack::Empty)
    {
        std::cout << "stack is empty" << std::endl;
    }


    return 0;
}