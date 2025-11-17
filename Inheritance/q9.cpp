
#include<iostream>

class Publication
{
    std::string title;
    float price;

    public:
    void getdata()
    {
        std::cout << "enter title: "; 
        std::getline(std::cin, title);
        
        std::cout << "price: "; 
        std::cin >> price;
        
        std::cin.ignore(); 
    }

    void putdata()
    {
        std::cout << "Title: " << title << std::endl
                    << "Price: " << price 
                    << std::endl;
    }


};



class Publication2  : public Publication
{
    int year;
    int month;
    int day;

    public:
    void getdata()
    {
        std::cout << "enter year of publication: "; std::cin >> year;
        std::cout << "enter year of month: "; std::cin >> month;
        std::cout << "enter year of day: "; std::cin >> day;
        std::cin.ignore();
    }

    void putdata()
    {
        std::cout << day << ":" << month << ":" << year << std::endl;
    }

};




class Book : public Publication2
{
    int pagecount;
    public:

     void getdata()
    {
        Publication :: getdata();
        
        std::cout << "enter pagecount: "; 
        std::cin >> pagecount;
        std::cin.ignore();
        
        Publication2 :: getdata();
       
    }

    void putdata()
    {
        Publication :: putdata();
        std::cout << "Pagecount: " << pagecount << std::endl;
        Publication2 :: putdata();
    }

};

class Tape : public Publication2
{
    float playing_time;

    public:
    void getdata()
    {
        Publication :: getdata();
        
        std::cout << "enter playing_time: "; 
        std::cin >> playing_time;
        std::cin.ignore();
        
        Publication2 :: getdata();
       
    }

    void putdata()
    {
        Publication :: putdata();
        std::cout << "Playing_time: " << playing_time << std::endl;
        Publication2 :: putdata();
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