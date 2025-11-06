
#include<iostream>


class A
{

    private:
    int privA = 10;

    protected:
    int protA = 20;

    public:
    int pubA = 30;


};



// private inheritance, protected and public of A become private in B, not available for further inheritance, can be accessed using member func only.
class B : private A
{
    private:
    int privB = 100;

    protected:
    int protB = 200;

    public:
    int pubB = 300;

    int get_protB()
    {
        return protB;
    }

    int get_privatB()
    {
        return privB;
    }
    
    int get_protA()
    {
        return protA;
    }

    int get_pubA()
    {
        return pubA;
    }

};



// protected inheritance, protected and public of A become protected in B, available for further inheritance, can be accessed using member func only.
class C : protected A
{
    int privC = 1000;

    protected:
    int protC = 2000;
    
    public:
    int pubC = 3000;

    int get_privC()
    {
        return privC;
    }

    int get_protC()
    {
        return protC;
    }

    int get_pubC()
    {
        return pubC;
    }

    int get_protA()
    {
        return protA;
    }

    int get_pubA()
    {
        return pubA;
    }
    
};


// since B was inherited privately, E cannot inherit the private data of class B
class E : public B
{
    public:
    /*
    int get_protA()
    {
        return protA;
    }

    int get_pubA()
    {
        return pubA;
    }
    */

    int get_protB()
    {
        return protB;
    }

    int get_pubB()
    {
        return pubB;
    }


};



// since C was inherited protected, F can inherit the protected data of class B
class F : public C
{

    public:
    int pubF = 100000;

    int get_protA()
    {
        return protA;
    }

    int get_pubA()
    {
        return pubA;
    }




};



// public inheritance, protected and public of A become public in B, available for further inheritance, can be accessed using objects of derived.
class D : public A
{
    private:
    int privD = 22;

    protected:
    int protD = 33;

    public:
    int pubD = 44;

    int get_privD()
    {
        return privD;
    }

    int get_protD()
    {
        return protD;
    }

    int get_pubD()
    {
        return pubD;
    }

    int get_protA()
    {
        return protA;
    }

    int get_pubA()
    {
        return pubA;
    }

};


// --- MAIN ---
int main()
{
    B b1;
    std:: cout << b1.pubB << std::endl;
   
    int x = b1.get_protB();
    int y = b1.get_privatB();
    int z = b1.get_protA();
    int m = b1.get_pubA();

    std::cout << x << " "
              << y << " "
              << z << " "
              << m << " "
              << std::endl;

    /*  not possible to access */
    //b1.protB;
    //b1.privB;
    //b1.protA;
    //b1.pubA;
    
    C c;
    //std::cout << c.privC; // private var cannot be accessed by class objects
    //std::cout << c.protC; // prot var cannot be accessed by class objects
    std::cout << c.pubC << std::endl;

    //c.protA; // since protected and public var of class A are now protected in C
    //c.pubA;

    std::cout << c.get_privC()<< " "
              << c.get_protC()<< " "
              << c.get_pubC()
              << std::endl;


    std::cout << c.get_protA() << " "
              << c.get_pubA() << " "
              << std::endl;


    E e;
    std::cout << e.get_protB() << " "
              << e.get_pubB() << std::endl;
    

    F f;
    std::cout << f.get_protA() << " "
              << f.get_pubA() << "  "
              << std::endl;


    D d;

    std::cout << d.pubD << " "
              << d.pubA << " " 
              << std::endl;

    std::cout << d.get_protA() << " "
              << d.get_protD() <<" "
              << d.get_privD() << " "
              << std::endl;

    return 0;   
}