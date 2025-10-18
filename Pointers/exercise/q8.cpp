/*       implementation linked list FIFO a.k.a queue       */

#include<iostream>


class Node
{
    public:
    int data;
    Node* next;

};


class List
{
    Node* head;
    public:
        List(){head=NULL;}

        void addNode(int);
        void display();

};



// --- Linked List ---
void List :: addNode(int d)
{
    Node* ptr = new Node;
    ptr->data=d;
    ptr->next = NULL;
    
    if(head==NULL)
    {
        head=ptr;
    }else{

    Node* current=head;

    while(current->next!=NULL)
    {
        current = current->next;
    }

    current->next = ptr;
    }


    
}



// --- display ---
void List :: display()
{
   Node* current = head;
   while(current!=NULL)
   {
    std::cout<<current->data<<std::endl;
    current=current->next;
   }
}



// --- MAIN ---
int main()
{
 List l1;
 l1.addNode(10);
 l1.addNode(20);
 l1.addNode(30);

 l1.display();

 return 0;
}

