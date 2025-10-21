
/* virtual base classes and multiple inheritance */

#include<iostream>

class Parent
{
    protected:
        int basedata;
};

// With the use of virtual keyword, both Child1 and Child2 refer to the same copy of basedata so no ambiguity
class Child1 : virtual public Parent
{   

};


class Child2 : virtual public Parent
{

};


class GrandChild : public Child1, public Child2
{
    public:
        int getdata()
        {
            return basedata;
        }
};