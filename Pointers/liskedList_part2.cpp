/* First In First Out Queue using LinkedList */

#include<iostream>

class Node
{
    public:
    int data;
    Node* next;
};

class LL
{
    Node* head ;
    public:
    LL(){head=NULL;}

    void addNode(int d)
    {
        // create the nodes
        Node* ptr = new Node;
        ptr->data=d;
        ptr->next=NULL;

        // linking
        if(head==NULL)
        {
            head=ptr;
        }else
        {
            Node* current = head;
            while(current->next!=NULL)
            {
                current = current->next;
            }
            current->next=ptr;
        }
    }

    void display()
    {
        Node* current = head;

        while(current!=NULL)
        {
            std::cout<<current->data<<" ";
            current=current->next;
        }
    }

    ~LL(){
        Node* ptr;
        ptr = head;

        while(ptr!=NULL)
        {
            Node* temp = ptr;
            ptr=ptr->next;
            delete temp;
            
            std::cout<<std::endl<<"deleted";
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