/*
 time and operator++ and --

 logic to handle overflow, like hours>23 , minutes > 60, seconds > 60, is not added
*/

#include<iostream>

class Time
{
    int hours, minutes, seconds;

    public:
    Time(): hours(0), minutes(0), seconds(0) {}

    Time(int h, int m, int s): hours(h), minutes(m), seconds(s) {}

    void display() const
    {
        std::cout << (hours<10 ? "0" :"") << hours << ":"
                  << (minutes<10 ? "0" :"")<< minutes << ":"
                  << (seconds<10 ? "0" : "") << seconds 
                  << std::endl;
    }

    // matches ++t1 // prefix
    void operator++()
    {
        hours+=1;
        minutes+=1;
        seconds+=1;
    }

    // matches t1++ // postfix
    Time operator++(int)
    {
       int temp_h = hours;
       int temp_m = minutes;
       int temp_s = seconds;
       
       hours++;
       minutes++;
       seconds++;

       return Time(temp_h,temp_m ,temp_s);
        
    }

};



// --- main ---
int main()
{
 Time t1(10, 14, 15);
 t1.display();

 //postfix
 Time t2 = t1++; // need an object to catch the old values
 std::cout << "postfix old value: "; 
 t2.display();
 std::cout << "postfix new value: ";
 t1.display();

 //prefix
 ++t1;
 std::cout << "prefix: ";
 t1.display();

 //postfix
 //t1++;
 //std::cout << "postfix:"; 
 //t1.display();

 return 0;
}