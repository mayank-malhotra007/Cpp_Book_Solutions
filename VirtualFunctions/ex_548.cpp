/* this and member data access */

#include<iostream>

class what
{
    int alpha;

    public:
        void tester()
        {
            this->alpha = 11;
            std::cout << this->alpha << std::endl;
        }
};

int main()
{
 what w;
 w.tester();

 return 0;
}
