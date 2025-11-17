#include<iostream>

template<typename T>
struct Node
{
    T data;
    Node<T>* next;   // FIXED
};

template<typename T>
class LinkList
{
    Node<T>* head;

    public:
    LinkList() : head(nullptr) {}

    void addItem(T d);
    void display();
};

template<typename T>
void LinkList<T>::addItem(T d)
{
    Node<T>* ptr = new Node<T>;
    ptr->data = d;
    ptr->next = nullptr;

    if (head == nullptr)
    {
        head = ptr;
        return;
    }

    // Traverse to end
    Node<T>* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    // Link new node
    current->next = ptr;
}

template<typename T>
void LinkList<T>::display()
{
    Node<T>* current = head;
    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    LinkList<int> l1;
    l1.addItem(10);
    l1.addItem(20);
    l1.addItem(30);

    l1.display();

    return 0;
}
