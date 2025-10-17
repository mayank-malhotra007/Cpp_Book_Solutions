/* linked list with a destructor */

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
    LL(){head=NULL;}

    void addNode(int);
    void display();

    ~LL()
    { 
        std::cout<<std::endl;
        std::cout<<"destructor called"<<std::endl;
        Node* current = head;
        while(current!=NULL)
        {
            Node* temp;
            temp = current->next;
            std::cout<<"deleted link for "<<current->data<<std::endl;
            current->next=NULL;
            current = temp;
        }

    }
};

// head points to last entry so LIFO aka stack
void LL :: addNode(int d)
{
    Node* ptr = new Node; // why new, because mem has to be assigned for data and next
    ptr->data = d;
    ptr->next = head;
    head=ptr;

}

void LL :: display()
{
  Node* current;
  current = head;
  while(current!=NULL)
  {
    std::cout<<current->data<<" ";
    current = current->next;
  }
}

int main()
{
 LL obj1;
 obj1.addNode(10);
 obj1.addNode(20);
 obj1.addNode(30);

 obj1.display();


 return 0;
}