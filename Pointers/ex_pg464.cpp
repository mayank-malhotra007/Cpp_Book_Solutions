/* pointers to objects */

#include<iostream>

// --- DISTANCE ---
class Distance{

    int feet;
    float inches;
    public:
        void getdist(){
            std::cout<<"enter feet: ";
            std::cin>>feet;
            std::cout<<"enter inches: ";
            std::cin>>inches;
        }


        void showdist(){
            std::cout<<feet<<"'"<<inches<<"\""<<std::endl;
        }

};


// ---- MAIN ----
int main(){
    Distance d1; // object1
    Distance d2; // object2
 
    Distance* d_ptr; //pointer to class Distance object 
    d_ptr = new Distance; // dyna allocated on heap
    d_ptr->getdist();
    d_ptr->showdist();

    //method1
    Distance* dd_ptr;
    dd_ptr = &d1; // on stack
    dd_ptr -> getdist();
    dd_ptr -> showdist();

    //method2
    Distance& dist = *(new Distance);
    dist.getdist();
    dist.showdist();

    delete d_ptr;  // we can only delete pointers on heap not stack

    return 0;
}