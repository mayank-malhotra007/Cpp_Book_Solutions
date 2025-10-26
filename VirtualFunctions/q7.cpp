
/* Parse program , aka Stack: FILO first in last out */
/* Parse : 3.14 / 2.0 + 75.25 * 3.33 + 6.02        */

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

    void push(int);
    void pop();
    void display();


};



void Stack :: push(int d)
{

  Node* ptr = new Node;
  ptr->data = d;
  ptr->next = head;
  head = ptr;
}

void Stack :: pop()
{
    if(head==nullptr)
    {
        std::cout << "stack is empty" << std::endl;
        return;
    }

    Node* current = head;
    std::cout<<"popped: "<<current->data<<std::endl;
    head = head->next;
    delete current;
    
}


void Stack::display()
{
    Node* current = head;

    while(current!=NULL)
    {
        std::cout << current->data << " ";
        current=current->next;
    }
}

int main()
{
 int n;
 Stack s1;
 for(int x=0; x<3 ; x++)
 {
    std::cout << "enter the data for node: ";
    std::cin >> n;
    s1.push(n);
 }
 
 s1.display();
 s1.pop();
 s1.pop();
 s1.pop();
 s1.pop();

 return 0;
}



