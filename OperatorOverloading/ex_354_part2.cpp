/* timers3.cpp */
// using copy assignment


#include<iostream>
#include<string>

class time24;

// -- class12 --
class time12
{
    bool pm;
    int hrs;
    int mins;

    public:
    time12(): pm(true), hrs(0), mins(0) {}

    time12(bool ap, int h, int m): pm(ap), hrs(h), mins(m)
    {}

    void display() const
    {
       
        std::string am_pm = pm? "pm" : "am";
       
        std::cout << (hrs<10? "0" : "")<< hrs 
                  << (mins<10? "0": "" ) << mins
                  << am_pm
                  << std::endl;
        
    }

   
    time12& operator=(const time24& rhs);

    

};

// copy assignment
time12& time12::operator=(const time24& rhs)
    {
        std::cout << "copy assignment invoked" << std::endl;
        
        int h24 = rhs.hours;
        int mins24 = rhs.minutes;
        int sec24 = rhs.seconds;
        bool am_pm = false;

        if(h24>=13 && h24<=23)
        {
            h24 = h24%12;
            am_pm = true;

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


        // call the 3-arg constructor of time12
        time12(am_pm, h24, mins24);
        
}



// -- time24 --
class time24
{
    friend class time12;
    int hours;
    int minutes;
    int seconds;

    public:
    time24(): hours(0), minutes(0), seconds(0){}

    time24(int h, int m, int s): hours(h), minutes(m), seconds(s)
    {}

    void display() const
    {
        std::cout << (hours<10 ? "0": "") << hours << ":"
                  << (minutes<10 ? "0": "") << minutes <<":"
                  << (seconds<10 ? "0": "") << seconds
                  << std::endl;

    }

   
     
};







// -- main --
int main()
{
    int h, m, s;
    char ch;

    do{
        std::cout << "enter 24-hour time:" << std::endl;
        std::cout << "Hours (0 to 23): ";
        std::cin  >> h;

        if(h>23) exit(1); 

        std::cout << "Minutes: ";
        std::cin >> m;

        std::cout << "Seconds: ";
        std::cin >> s;

        time24 t24(h,m,s);

        t24.display();

        
        time12 t12;
        t12 = t24; // copy assignment call

        t12.display();

        std::cout << "enter once more? y/n: ";
        std::cin >> ch;

        

    }while(ch=='y');

 return 0;
}