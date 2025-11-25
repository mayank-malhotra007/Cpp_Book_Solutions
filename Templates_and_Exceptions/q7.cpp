
#include<iostream>

template<typename T>
class Frac
{
 
  T a, b, c, d;  
    
  public:
  
    void getFraction()
    {
        std::cout<<"enter a: "; std::cin >> a;
        std::cout << "enter b: "; std::cin >> b;
        std::cout << "enter c: "; std::cin >> c;
        std::cout <<"enter d: "; std::cin >> d;
    }

    void add()
    {
        std::cout << a << "/" << b
                  << " + "
                  << c << "/" << d
                  <<std::endl;


        T num =  (a*d)+(b*c) ;
        T denom = (b*d) ;
        
        std::cout << num << "/" <<denom << std::endl;
    }




};


// --- MAIN ---
int main()
{
 Frac<int> f1;
 Frac<float> f2;

 // sum of integer fractions
 f1.getFraction();
 f1.add();
 //std::cout << "result of addition: " << sum << std::endl;



 // sum of char fractions
 f2.getFraction();
 f2.add();
 //std::cout << "result of addition: " << sum_char << std::endl;



 //f1.sub();
 //f1.mult();
 //f1.div();




 return 0;
}
