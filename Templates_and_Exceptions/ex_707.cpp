/*
 a simple exception example 
*/

#include<iostream>
const int MAX = 3;

class Stack
{
  int st[MAX];
  int top;

  public:

  class Range
  {};

  Stack() {top=-1;}

  void push(int d)
  {
    if(top>=MAX-1)
    {
        throw Range();
    }
    else{
            st[++top] = d; 
        }
    }

  int pop()
  {
    if(top<0)
    {
        throw Range();
    }
    else{
        return st[top--];
    }
  }
    
};

// ---- MAIN ----
int main()
{
    Stack s1;

    try
    {
        s1.push(1);
        s1.push(2);
        s1.push(3);
        s1.push(4); // error
    }catch(Stack::Range)
    {
        std::cout << "exception caught : stack full or empty" << std::endl;
    }

    
 return 0;
}