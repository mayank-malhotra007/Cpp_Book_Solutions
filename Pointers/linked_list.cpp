/* chain of pointers linked list */




#include<iostream>


struct link
{
    int data;
    link* next; // pointer to a struct object 
};



class linklist
{
    link* first;
    public:
        linklist()
        {
            first=NULL;
        }

        void additem(int d);
        void display();

};



void linklist::additem(int d)
{
    link* newlink=new link; // a new pointer created that points to an object of type struct
    newlink->data=d;
    newlink->next = first;
    first = newlink;

}



void linklist::display()
{
    link* current = first;
    while(current!=NULL)
    {
        std::cout<<current->data<<" ";
        current= current->next;
    }
}



int main()
{
    linklist l1;
    l1.additem(10);
    l1.additem(20);
    l1.additem(30);

    l1.display();
    return 0;
}