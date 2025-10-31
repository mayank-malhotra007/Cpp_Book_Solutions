/* timers1.cpp */

#include<iostream>
#include<string>


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
       
        //using conditional operators 
        std::cout << (hrs<10? "0" : "")<< hrs 
                  << (mins<10? "0": "" ) << mins
                  << am_pm
                  << std::endl;
        
    }
};


// -- time24 --
class time24
{
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
    // time12 is a class
    operator time12() const;
    
     
};

time24 :: operator time12() const
{
    std::cout << "operator() invoked" << std::endl;
    std::cout << "hours: " << hours << std::endl;
    std::cout << "minutes: " << minutes << std::endl;
    std::cout << "seconds: " << seconds << std::endl;

    int h=0, m=0;
    bool value=false;

    if(hours>=13 && hours <=23)
    {
        h = hours%12;
        value = true;
    }
    else
    {
        h = hours;
        value = false;
    }

    //midnight, so am
    if(hours == 0)
    {
        value = false; 
    }

    // noon , so pm
    if(hours == 12)
    {
        value = true;
    }

    if(minutes>=60)
    {
        m = 0;
        h++;
    }
    else
    {
        m = minutes;
    }

    if(seconds >= 60)
    {
        m +=1;
    }



    return time12(value, h, m);
}



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

        // operator time12() is invoked
        time12 t12 = t24;
        t12.display();

        std::cout << "enter once more? y/n: ";
        std::cin >> ch;

        

    }while(ch=='y');

 return 0;
}