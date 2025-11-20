/*
 Implementation of a Queue as a template
*/

#include<iostream>

template<typename T>
class Node
{
    public:
    T data;
    Node<T>* next; 
};

template<typename T>
class Queue
{
    Node<T>* head;
    Node<T>* tail;

    public:
    Queue() {
        head=nullptr;
        tail=nullptr;
    }

    void addItem(T d);
    void pop();
    void display();

};

template<typename T>
void Queue<T>::addItem(T d)
{
    Node<T>* ptr = new Node<T>;
    ptr->data = d;
    ptr->next = nullptr;

    if(head == nullptr)
    {
        head = ptr;
    }

    else
    {
        tail = head;
        while(tail->next!=nullptr)
        {
            tail = tail->next;
        } 

        tail -> next = ptr;
        tail = ptr;
    }
  

}


template<typename T>
void Queue<T> :: display()
{

    Node<T>* first = head;
    Node<T>* last = tail;

    std::cout << "[ ";
    while(first != NULL)
    {
        std::cout << first->data <<" ";
        first=first->next;
    }
    std::cout << "]";

}

template<typename T>
void Queue<T> :: pop()
{
  
  std::cout << std::endl;
  while(head!=tail)
  {
    Node<T>* first;
    std::cout <<"element popped: " <<head->data << std::endl;;
    first = head;
    head = head->next;
    delete first;

    if(head==tail)
    {
       std::cout << "last element: " << head->data << std::endl;
       std::string error = "queue empty";
       throw error;
    }
  }
}

// --- MAIN ---
int main()
{
 Queue<int>   q1;
 Queue<float> q2;
 Queue<double> q3;

 // -- Queue 1 ---
 q1.addItem(1);
 q1.addItem(2);
 q1.addItem(3);

 q1.display();

 try{
    q1.pop();
    q1.pop();
    q1.pop();
    q1.pop();

 }catch(std::string& e)
 {
    std::cout << e << std::endl;
 }


 // -- Queue 2 --
 q2.addItem(1.5);
 q2.addItem(2.5);
 q2.addItem(3.5);

 std::cout << std::endl;
 q2.display();

 // Queue 3 --
 q3.addItem(10000);
 q3.addItem(20000);
 q3.addItem(30000);

 std::cout << std::endl;
 q3.display();

 return 0;
}