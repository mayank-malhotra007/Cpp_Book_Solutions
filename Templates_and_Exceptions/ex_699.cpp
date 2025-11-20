/*
 - Implemented a linkedlist using templated and class object
 - invoking istream >> and ostream <<
*/



#include<iostream>
const int LEN = 80;

class Employee
{
    char name[LEN];
    unsigned long number;

    public:
    friend std::istream& operator>>(std::istream& s, Employee& e);
    friend std::ostream& operator<<(std::ostream& os, Employee& e);
};



std::istream& operator>> (std::istream& s, Employee& e)
{
    std::cout << "enter name: ";
    std::cin >> e.name;

    std::cout << "enter number: ";
    std::cin >> e.number;
    return s;
}


std::ostream& operator<< (std::ostream& os, Employee& e)
{
    os << e.name << ":" << e.number << std::endl;
    return os;
}


// code for linkedlist
template<typename T>
struct Node
{
    T data;
    Node<T>* next;
};


template<typename T>
class List
{
    Node<T>* head;

    public:
    List(): head(nullptr) {}

    void addItem(T x)
    {
        Node<T>* ptr = new Node<T>;
        ptr->data = x;
        ptr->next = head;
        head = ptr;
    }

    void display()
    {
        Node<T>* current = new Node<T>;
        current = head;

        while(current!=NULL)
        {
            std::cout << current->data; // since its printing an object , the operator ostream << is invoked
            current = current->next;
        }
    }
};


// --- MAIN ---
int main()
{
 List<Employee> l1;
 
 Employee e1;
 std::cout << "enter details for employee: " << std::endl;
 std::cin >> e1;

 std::cout << "entered data for employee is: " << std::endl;
 std::cout << e1;
 
 Employee e2;
 std::cout << "enter details for employee: " << std::endl;
 std::cin >> e2;

 std::cout << "entered data for employee is: " << std::endl;
 std::cout << e2;

 //add employee objects to linkedlist
 l1.addItem(e1);
 l1.addItem(e2);

 //display

 std::cout << "printing linked list" << std::endl;
 l1.display();

 return 0;
}
