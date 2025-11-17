
#include <iostream>


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


class Disk : public Publication
{

    enum disktype {cd, dvd};
    char ch;
    public:
    
    void getdata()
    {
        Publication :: getdata();
        std::cout << "enter disktype [c:cd / d:dvd] : ";
        std::cin >> ch;
    }

    int putdata()
    {
        Publication :: putdata();
        if (ch == 'c') {return cd; }
        else if (ch == 'd') {return dvd;}
        else { return -1;}
    }

};

// -- MAIN --
int main()
{

    Disk d1;
    d1.getdata();
    int x =d1.putdata();

    if(x==0) std::cout << "cd" << std::endl;
    else if(x==1) std::cout << "dvd" << std::endl;


 return 0;
}


