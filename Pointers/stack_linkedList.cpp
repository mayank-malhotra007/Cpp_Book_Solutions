/* stack -> ADT abstarct data type */
/* implemented as a LL ot Array */

#include<iostream>

class Node{
    public:
        int data;
        Node* next;

        Node(int d): data(d), next(NULL){}

};


class Stack
{
    
    Node* top;
   
    public:
        Stack(){top=NULL;}

        void push(int d);
        void pop();

};


void Stack :: push(int d)
{
    Node* newNode =new Node(d);

    newNode->next = top;
    top = newNode;
    std::cout<<"pushed to stack"<<std::endl;


}

void Stack :: pop()
{
    try{
    if(top==NULL)
    {
        std::cout<<"stack is empty!";
        throw 0;
    }
    }catch(const int& x)
    {
        std::cout<<"out of memory"<<std::endl;
    }

    int x = top->data;
    Node* temp = top;
    delete temp;

    std::cout<<"popped"<<x<<std::endl;
}


int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();


    return 0;
}