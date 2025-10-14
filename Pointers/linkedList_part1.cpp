/* Last In First Out LIFO (aka Stack) using LinkedList */

#include<iostream>

class Node
{
   public:
   int data;
   Node* next;
};


class LL
{
    Node* head;
    public:
    LL(){head=NULL;};

    void addNode(int d)
    {
        Node* ptr = new Node;
        std::cout<<"ptr value: "<<ptr<<std::endl;
        std::cout<<"head value: "<<head<<std::endl;
        ptr->data = d;
        ptr->next = head;
        head=ptr;
    }

    void display()
    {
        Node* current;
        current = head;

        while(current!=NULL)
        {
            std::cout<<current->data<<" ";
            current=current->next;
        } 
    }

    //-- release memory --
    ~LL()
    {
        Node* current=head;
        while(current!=NULL)
        {
            Node* temp = current;
            current=current->next;
            delete temp;
            std::cout<<"deleted"<<std::endl;
        }
    }
};



int main()
{
    LL l1;
    l1.addNode(10);
    l1.addNode(20);
    l1.addNode(30);

    l1.display();

  
    return 0;
}