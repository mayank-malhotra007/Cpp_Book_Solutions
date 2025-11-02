
/*
    time class
*/

#include<iostream>


class Time
{
    int hours, minutes, seconds;

    public:
    Time():hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s): hours(h), minutes(m), seconds(s) {}

    void display() const
    {
        std::cout << (hours<10? "0": "") << hours << ":"
                  << (minutes<10? "0": "") << minutes << ":"
                  << (seconds<10?"0":"") << seconds 
                  << std::endl;
    }


    Time operator+(const Time& rhs) const
    {
        int temp_h = hours + rhs.hours;
        
        if(temp_h>23)
        {
            temp_h = temp_h % 24;
        }
        
        int temp_minutes = minutes + rhs.minutes;

        if(temp_minutes>60)
        {
            temp_minutes-=60;
            temp_h+=1;
        }

        int temp_seconds = seconds + rhs.seconds;

        if(temp_seconds>60)
        {
            temp_seconds-=60;
            temp_minutes+=1;
        }



        return Time(temp_h, temp_minutes, temp_seconds);
    }
};



// -- MAIN --
int main()
{

 const Time t1(4, 5, 5);
 const Time t2(3, 9,9);


 t1.display();
 t2.display();

 Time t3;
 t3 = t1 + t2;

 t3.display();


 return 0;
}