
#include<iostream>

const int MAX = 5;

template<typename Type>
class Stack
{
    Type st[MAX];
    int top;

    public:
    Stack()
    {
        top = -1;
    }

    void push(int d)
    {
        if(top==MAX-1)
        {
            std::cout << "stack full" << std::endl;
        }
        else{
        top++;
        st[top] = d;
        }
    }

    int pop()
    {
        if(top==-1)
        {
            std::cout << "stack empty" << std::endl;
            return -1;
        }
       else
       {
            int result = st[top--];
            return result;
        }
    }
};


// --- MAIN ---
int main()
{
    // stack of float variables
    Stack<float> s1;

    s1.push(2);
    s1.push(3);
    s1.push(4);

    std::cout << s1.pop() << std::endl;
    std::cout << s1.pop() << std::endl;

    // stack of long variables
    Stack<long> s2;
    s2.push(18000L);
    s2.push(1999L);

    s2.pop();

 return 0;
}