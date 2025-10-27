
/*
   Copy a linked list using pointers
*/

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
    List(){head=nullptr;}

    void addNode(int);
    void display();

    //copy assignment
    List& operator=(const List& rhs)
    {
        std::cout << "copy assignment called" << std::endl;

        // check self assignment
        if(this == &rhs)
        {
            std::cout << "self assignment !" << std::endl;
            return *this;
        }

       
        
        Node* c = head;
        // delete existing nodes
        while(c)
        {
            Node* temp = c;
            c = c->next;
            delete temp;
        }

        // created new Nodes
        Node* current = rhs.head;
        Node* last = nullptr;
       
        while(current!=NULL)
        {
            
            Node* ptr = new Node;
            ptr->data = current->data;
            ptr->next = nullptr;
            
            if(last==nullptr)
            {
               head=ptr;
            }
            else
            {
                // linking new nodes
                last->next = ptr;
                
            }

            // traverse original
            last = ptr;
            current = current->next;
    
        }

        return *this;
    }

    ~List()
    {
        std::cout << "destructor called" << std::endl;

        // deletion of links
        Node* current = head;
        while(current)
        {
            Node* temp = current;
            current = current->next;
            delete temp; 
        }
    }

};



void List::addNode(int d)
{
    Node* ptr = new Node;
    ptr->data = d;
    ptr->next = head;
    head=ptr;
}

void List::display()
{
    Node* current = head;
    while(current!=NULL)
    {
        std::cout << current->data << std::endl;
        current = current->next;
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

  // copy assignment for List object
  List l3;
  l3 = l1;

  l3.display();

 return 0;
}



