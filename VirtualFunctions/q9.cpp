
/*
   Copy a linked list using pointers,
   Default copy constructor (and also the default copy assignment operator) in C++ performs a shallow copy, not the default constructor itself.
   List1 pointer and List3 pointers are copied, with default constructor , if l1 is deleted then l3 is dangling,
   With custom copy constructor , even if l1 is deleted, l3 survives
   
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

        // step1. check self assignment
        if(this == &rhs)
        {
            std::cout << "self assignment !" << std::endl;
            return *this;
        }

       
        // step 2. delete existing nodes
        Node* c = head;
     
        while(c)
        {
            Node* temp = c;
            c = c->next;
            delete temp;
        }

        // step 3. created new Nodes
        Node* current = rhs.head;
        Node* last = nullptr;
       
        while(current!=NULL)
        {
            // deep copy, since we create a new pointer and allocate it memory, even if l1 is deleted, l3 will survive!
            // default copy constructor uses shallow copy, if l1 is deleted, l3 crashes, its a dangling pointer!

            Node* ptr = new Node;
            ptr->data = current->data;
            ptr->next = nullptr;
            
            if(last==nullptr)
            {
               head=ptr;
            }
            else
            {
                // step 4. linking new nodes
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
  List* l1 = new List;

  l1->addNode(10);
  l1->addNode(20);
  l1->addNode(30);

  l1->display();

  
  List* l3 = new List;

  *l3 = *l1; // copy assignment invoked

  delete l1;

  l3->display();
  
  delete l3;

  return 0;
}



