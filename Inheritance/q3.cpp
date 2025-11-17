#include <iostream>
#include <string>
#include <limits>

class Publication {
    std::string title;
    float price;
public:
    void getdata() {
        std::cout << "Enter title: ";
    
        
        std::getline(std::cin, title);

        std::cout << "Enter price: ";
        std::cin >> price;
    }

    void putdata() {
        std::cout << "\nTitle: " << title
                  << "\nPrice: " << price << std::endl;
    }
};

class Sales {
    float sale[3];
public:
    void getdata() {
        std::cout << "Enter sales for last 3 months: ";
        for (int i = 0; i < 3; i++) std::cin >> sale[i];
    }
    void putdata() {
        std::cout << "Sales for last 3 months: ";
        for (int i = 0; i < 3; i++) std::cout << sale[i] << " ";
        std::cout << std::endl;
    }
};

class Book : public Sales, public Publication {
    int pagecount;
public:
    void getdata() {
        Publication::getdata();
        std::cout << "Enter page count: ";
        std::cin >> pagecount;
        Sales::getdata();
        // add after the last numeric input and before title is fetched
        std::cin.ignore();
    }
    void putdata() {
        Publication::putdata();
        std::cout << "Page count: " << pagecount << std::endl;
        Sales::putdata();
    }
};

class Tape : public Sales, public Publication {
    float playing_time;
public:
    void getdata() {

        Publication::getdata();
        std::cout << "Enter playing time (minutes): ";
        std::cin >> playing_time;
        Sales::getdata();
        // add after the last numeric input and before title is fetched
        std::cin.ignore();
    }
    void putdata() {
        Publication::putdata();
        std::cout << "Playing time: " << playing_time << " minutes" << std::endl;
        Sales::putdata();
    }
};

int main() {
    Book b1;
    Tape t1;

    std::cout << "Enter details for book:\n";
    b1.getdata();

    std::cout << "\nEnter details for tape:\n";
    t1.getdata();

    std::cout << "\n--------------------------\n";

    b1.putdata();
    t1.putdata();

    return 0;
}
