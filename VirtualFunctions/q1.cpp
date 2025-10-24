
#include<iostream>

class Publication
{
    std::string title;
    float price;

    public: 
    virtual void getdata()
    {
        std::cout << "enter title: ";
        std::cin  >> title;
        std::cout << "enter price: ";
        std::cin  >> price;
    }
    virtual void putdata()
    {
        std::cout << "title is: " << title << std::endl;
        std::cout << "price is: " << price << std::endl;
    }

};

class Book : public Publication
{
    int page_count;

    public:
    void getdata()
    {
        Publication::getdata();
        std::cout << "enter page count: ";
        std::cin>>page_count;
    }
    void putdata()
    {
        Publication::putdata();
        std::cout << "page count is: " << page_count << std::endl;
    }

};


class Tape : public Publication
{
    float playing_time;

    public:
    void getdata()
    {
        Publication::getdata();
        std::cout << "enter playing_time: ";
        std::cin  >> playing_time;

    }
    void putdata()
    {
        Publication::putdata();
        std::cout << "playing time is: ";
        std::cout << playing_time;
    }

};


// --- MAIN ---
int main()
{
 int x;
 Publication* pub_arr[100];
 char ch;

 do
 {
  int n;
  std::cout << "enter [1:book, 2: tape]: ";
  std::cin>>n;
  

  if(n==1)
  {
    Publication* pb = new Book();
    pb->getdata();
    pub_arr[x] = pb;
    x++;
    
  }
  else if(n==2)
  {
    Publication* pt = new Tape();
    pt->getdata();
    pub_arr[x] = pt;
    x++;
  }
  else
  {
    std::cout << "entered wrong choice, enter again";
  }

  std::cout <<"Would you like to create a new entry? [Y/N]: ";
  std::cin>>ch;

 }while(ch=='y' || ch == 'Y');


 // display 
 std::cout << "displaying entries" << std::endl;
 for(int i=0; i<x; i++)
 {
    pub_arr[i]->putdata();
 }

 return 0;
}