/* stack using a Linked List */

#include<iostream>

class Node
{
    public:
    int data;
    Node* next;
};


class Stack
{
    Node* top;
    public:
    Stack(){top=NULL;}

    void push(int d)
    {
            Node* node = new Node;
            node->data=d;
            node->next = top;
            top = node;    
    }

    void pop()
    {
        if(top==NULL)
        {
            std::cout<<"stack empty"<<std::endl;

        }
        else
        {
            Node* current = top;
            std::cout<<"popped: "<<current->data<<std::endl;
            top=top->next;
            delete current;
        }
    }

    int peek()
    {
        if(top == NULL)
        {
            std::cout<<"empty stack";
            return -1;
        }
        return top->data;
    }

};


int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    s.pop();
    s.pop();

    s.peek();


    return 0;
}


