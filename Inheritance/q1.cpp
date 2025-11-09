
#include<iostream>

class Publication
{
    std::string title;
    float price;

    public:
    void getdata()
    {
        std::cout << "enter title: "; 
        
        std::cin.ignore(); // to clear the buffer of \n
        std::getline(std::cin, title);
        std::cout << "price: "; std::cin >> price;
    }

    void putdata()
    {
        std::cout << "Title: " << title << std::endl
                    << "Price: " << price 
                    << std::endl;
    }


};

class Book : public Publication
{
    int pagecount;
    public:

     void getdata()
    {
        Publication :: getdata();
        std::cout << "enter pagecount: "; std::cin >> pagecount;
       
    }

    void putdata()
    {
        Publication :: putdata();
        std::cout << "Pagecount: " << pagecount << std::endl;
    }

};

class Tape : public Publication
{
    float playing_time;

    public:
    void getdata()
    {
        Publication :: getdata();
        std::cout << "enter playing_time: "; std::cin >> playing_time;
       
    }

    void putdata()
    {
        Publication :: putdata();
        std::cout << "Playing_time: " << playing_time << std::endl;
    }


};


// --- MAIN ---
int main()
{
  Book b1;
  b1.getdata();

  Tape t1;
  t1.getdata();

  b1.putdata();
  t1.putdata();

 std::cout << std::endl;
 return 0;
}