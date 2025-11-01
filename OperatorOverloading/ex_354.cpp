/*. timers2.cpp */
// using constructor()


#include<iostream>

class time24
{
    int hours;
    int minutes;
    int seconds;

    public:
    time24(): hours(0), minutes(0), seconds(0){std::cout<<"defaut"<<std::endl;}

    time24(int h, int m, int s): hours(h), minutes(m), seconds(s) {std::cout<<"3 args time24"<<std::endl;}

    void display() const
    {
        std::cout << (hours<10 ?"0": "") << hours << ":"
                  << (minutes<10?"0": "") << minutes <<":"
                  << (seconds<10?"0": "") << seconds 
                  << std::endl;
    }


    int getHrs() const  {return hours;}
    int getMins() const {return minutes;}
    int getSecs() const {return seconds;}

    //operator time12();


};


class time12
{

    bool pm;
    int hrs;
    int mins;

    public:
    time12(): pm(false), hrs(0), mins(0) {std::cout<<"default time12"<<std::endl;}

    time12(bool ap, int h, int m): pm(ap), hrs(h), mins(m) {std::cout<<"3 args time12"<<std::endl;}

    time12(time24); //1-arg constructor

    void display() const
    {
        std::cout<<((hrs<10)?"0":"")<<hrs << ":"
                 <<((mins<10)?"0":"")<<mins << " "
                 << (pm==false ? "am" : "pm") << std::endl;
        
    }
};


// using a constructor approach
time12::time12(time24 t24)
{
   int h24 = t24.getHrs();
   int mins24 = t24.getMins();
   int sec24 = t24.getSecs();


   std::cout << "hours: " << h24 << std::endl;
   std::cout << "mins: " << mins24 << std::endl;
   std:: cout << "seconds" << sec24 << std::endl;

    if(h24>=13 && h24 <=23)
    {
        h24 = h24%12;
        pm = true;
    }

    if(mins24>=60)
    {
        mins24-=60;
        h24+=1;
    }

    if(sec24>=60)
    {
        sec24-=60;
        mins24+=1;
    }

    // assign to original values
    hrs = h24;
    mins = mins24;


    //check noon and midnight
    if(hrs==0) {pm=false;}
    if(hrs==12) {pm = true;}


}


// main()
int main()
{
 int h, m ,s ;
 char ch;

 do
 {
 
  std::cout << "enter 24 hour-time (0-23)" << std::endl;
  
  std::cout << "enter hours: ";
  std::cin >> h;
  
  std::cout << "enter minutes: ";
  std::cin >> m;

  std::cout << "enter seconds: ";
  std::cin >> s;


  time24 t24(h,m,s);
  t24.display();


  // copying a class object into another
  // 1. copy constructor
  // 2. overload () operator
  time12 t12 = t24;

  std::cout << "12-hour time" << std::endl;
  t12.display();
 

 
 std::cout << "enter again?: y/n";
 std::cin >> ch;

 }while(ch=='y' || ch == 'Y');

 return 0;
}