/*.    using a comparator to to sort weekdays.   */

#include<iostream>
#include<string>


class Week
{
    const char** ptr;
    public:
        Week(const char** s): ptr(s){}

        void display(const char** ,int len);
        void compare(const char**, int len);
        void swap(const char**, int,int);


};

// helper

int dayOrder(const char* day)
{
    if(strcmp(day,"Mon")==0) return 1;
    else if(strcmp(day,"Tue")==0) return 2;
    else if(strcmp(day,"Wed")==0) return 3;
    else if(strcmp(day,"Thur")==0) return 4;
    else if(strcmp(day,"Fri")==0) return 5;
    else if(strcmp(day,"Sat")==0) return 6;
    else if(strcmp(day,"Sun")==0) return 7;
    else return 8;
}


// -- display --
void Week :: display(const char** p, int len)
{
    for(int x=0; x<len; x++)
    {
        std::cout<<*(p+x)<<std::endl;
    }
}


// -- compare --
void Week::compare(const char** pp, int l)
{
    for (int i = 0; i < l-1 ; i++)
    {
        for (int j = i+1 ; j < l; j++)
        {
            if(dayOrder(*(pp+i))>dayOrder(*(pp+j)))
            {
                swap(pp,i,j);
            }
        }
    }
}



// -- swap --
void Week :: swap(const char** pp, int i, int j)
{
    const char* temp = *(pp+i);
    *(pp+i) = *(pp+j);
    *(pp+j) = temp;
}


// --------------- MAIN --------------------
int main()
{
 const char* weekdays[] = {"Tue", "Mon", "Fri", "Thur", "Wed", "Sun", "Sat"};
 Week w1(weekdays);
 int len = 7;

 std::cout<<" -------- Before Compare ------ "<<std::endl;
 w1.display(weekdays,7);


 w1.compare(weekdays,7);

 std::cout<<" -------- After Compare --------"<<std::endl;
 w1.display(weekdays,7);

 return 0;   
}