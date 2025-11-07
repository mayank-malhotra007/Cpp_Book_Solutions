/*
    pubriv.cpp
*/

class A
{
    private:
    int privdataA;

    protected:
    int protdataA;

    public:
    int pubdataA;
};


class B : public A
{
    public:
    void funct()
    {
        int a;
        //a = privdataA; // not possible
        a = protdataA;
        a = pubdataA;
    }
};


class C : private A
{

    void funct()
    {
        int a;
        //a = privdataA;
        a = protdataA;
        a = pubdataA;
    }
};

int main()
{
    B objB;
    //objB.protdataA;
    objB.pubdataA;

    C objC;
    //objC.protdataC; since C inherits privately from A
    //objC.pubdataC;
}