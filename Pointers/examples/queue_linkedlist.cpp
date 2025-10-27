
/* Queue: FIFO using linked list*/

#include<iostream>

class Node
{

    public:
    int data;
    Node* next;
};


class Stack
{
    Node* head;
    public:

    Stack(){head=nullptr;}

    void addNode(int );
    void display();

};


void Stack :: addNode(int d)
{
    Node* ptr = new Node();
    ptr->data = d;
    ptr->next = nullptr;
    Node* current;

    if(head==nullptr)
    {
        head = ptr;
        current=head;
    }
    else
    {
            current->next = ptr;
            current=ptr;
        
    }
   
}


void Stack :: display()
{
    Node* current = new Node;
    current = head; 

    while(current!=NULL)
    {
        std::cout<<current->data<<std::endl;
        current=current->next;
    }
}


int main()
{
 Stack s1;
 s1.addNode(10);
 s1.addNode(20);
 s1.addNode(30);

 s1.display();
    
 return 0;
}