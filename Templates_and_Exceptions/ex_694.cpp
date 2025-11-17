
#include<iostream>

const int MAX = 5;

template<typename T>
class Stack
{
    T st[MAX];
    int top;

    public:

    Stack();
    void push(T d);
    T pop();

};

template<typename T>
Stack<T> :: Stack()
{
    top = -1;
}

template<typename T>
void Stack<T> :: push(T d)
{
    st[++top] = d;
}

template<typename T>
T Stack<T> :: pop()
{
    T result = st[top--];
    return result;
}

// --- MAIN ---
int main()
{
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);

    std::cout << s1.pop();

    Stack<long> s2;
    s2.push(10000L);
    s2.push(300000L);

    std::cout << s2.pop();


    return 0;
}


