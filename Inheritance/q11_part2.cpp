
#include<iostream>

struct Pair
{
    int x;
    int y;
};



class Stack
{
    protected:
    
    enum {MAX=3};
    int st[MAX];
    int top;

    public:
    Stack()
    {
        top = -1;
    }

    void push(int var)
    {
        st[++top] = var;
    }

    int pop()
    {
        return st[top--];
    }

};


class Stack2  : public Stack
{

    public:
    void push(int var)
    {
        if(top >= MAX-1)
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
            std::cout << "empty stack" << std::endl;
            exit(1);
        }
        else
        {
            return Stack :: pop();
        }
    }
};


class pairStack : public Stack2
{

};


int main()
{
 pairStack ps1;

 Pair p1;
 std::cout << "enter x coordinate: "; std::cin >> p1.x;
 std::cout << "enter y coordinate: "; std::cin >> p1.y;

 std::cout << "coordinates pushed on stack" << std::endl;
 ps1.push(p1.x);
 ps1.push(p1.y);


 std::cout << "elements popped from stack" << std::endl;
 int y_cd = ps1.pop();
 int x_cd = ps1.pop();

 std::cout << x_cd << "," << y_cd << std::endl;


 return 0;
}