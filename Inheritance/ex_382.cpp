/*
    overriding member functions
*/

#include<iostream>
const int MAX = 3;

class Stack
{
    protected:
    int st[MAX];
    int top;

    public:
    Stack() {top=-1;}

    void push(int var)
    {
        st[++top] = var;
    }

    int pop()
    {
        return st[top--];
    }


};


class Stack2 : public Stack
{
    public:
    void push(int var)
    {
        if(top >=MAX-1)
        {
            std::cout << "stack full" << std::endl;
            exit(1);
        }
        else
        {
            Stack :: push(var);
        }
    }

    int pop()
    {
        if(top==-1)
        {
            std::cout << "stack empty" << std::endl;
            exit(1);
        }
        else
        {
           return Stack :: pop();
        }
    }
};


// -- MAIN --
int main()
{
 Stack2 s1;
 s1.push(10);
 s1.push(20);
 s1.push(30);
 

 std::cout << s1.pop() << std::endl;
 std::cout << s1.pop() << std::endl;
 std::cout << s1.pop() << std::endl;
 std::cout << s1.pop() << std::endl;


 return 0;
}
