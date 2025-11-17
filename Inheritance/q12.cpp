/*
    For unary operators : +=, -=, ++, --, *=, /=, !=
    return *this , hence be reference as no new object is created

    For binary operators: + , -, *, /, %
    return a copy, hence a new object is created
*/


#include <iostream>

class Sterling {
protected:
    int pounds;
    int shillings;
    int pence;

public:
    Sterling() : pounds(0), shillings(0), pence(0) {}
    Sterling(int pd, int sh, int pe) : pounds(pd), shillings(sh), pence(pe) {
        
    }

    int get_pounds() { return pounds; }
    int get_shillings() { return shillings; }
    int get_pence() { return pence; }

    int total_pence() {
        return pounds * 240 + shillings * 12 + pence;
    }

    void normalize() {
        if (pence >= 12) {
            shillings += pence / 12;
            pence %= 12;
        }
        if (shillings >= 20) {
            pounds += shillings / 20;
            shillings %= 20;
        }
    }

    void convert_from_pence(int total_pence) {
        pounds = total_pence / 240;
        int rem = total_pence % 240;
        shillings = rem / 12;
        pence = rem % 12;

        normalize();
    }

    void display() {
        std::cout << "£" << pounds << "." << shillings << "." << pence;
    }

   
};

// Extended Sterling with halfpennies and farthings
class Sterling2 : public Sterling {
    int halfpennies;
    int farthings;

public:
    Sterling2() : halfpennies(0), farthings(0), Sterling() {}
    Sterling2(int pd, int sh, int pe, int hp, int ft)
        : Sterling(pd, sh, pe), halfpennies(hp), farthings(ft) {
          
    }

    int total_farthings() {
        return total_pence() * 4 + halfpennies * 2 + farthings;
    }

    void convert_from_farthings(int total_farthings) {
        pounds = total_farthings / 960;
        int rem = total_farthings % 960;

        shillings = rem / 48;
        rem %= 48;

        pence = rem / 4;
        rem %= 4;

        halfpennies = rem / 2;
        farthings = rem % 2;

        normalize();
    }

    void display()  {
        Sterling::display();
        std::cout << "." << halfpennies << "." << farthings << std::endl;
    }

    void normalize() {
        if (farthings >= 2) {
            halfpennies += farthings / 2;
            farthings %= 2;
        }
        if (halfpennies >= 2) {
            pence += halfpennies / 2;
            halfpennies %= 2;
        }
        Sterling::normalize();
    }

    // here we create a new object, return a copy
    Sterling2 operator+(Sterling2& rhs)
    {
        int new_pounds    = pounds + rhs.get_pounds();
        int new_shillings = shillings + rhs.get_shillings();
        int new_pence     = pence + rhs.get_pence();

        int new_halfpennies = halfpennies + rhs.halfpennies;
        int new_farthings = farthings + rhs.farthings;

        
        //creates a new object
        Sterling2 result(new_pounds, new_shillings, new_pence,new_halfpennies,new_farthings);

        result.normalize();
        return result;

    }
};

// --- MAIN ---
int main() {
    Sterling s1(3, 25, 50); // arbitrary values
    std::cout << "Original Sterling: ";
    s1.display();

    
    s1.convert_from_pence(s1.total_pence());
    std::cout << "\nAfter conversion: ";
    s1.display();
    std::cout << std::endl;

    
    Sterling2 s2(3, 25, 50, 34, 12);
    std::cout << "Original Sterling2: ";
    s2.display();

    s2.convert_from_farthings(s2.total_farthings());
    std::cout << "After farthing conversion: ";
    s2.display();


    Sterling2 s3(4,45,75,22,10);
    s3.display();
    //add the two objects
    Sterling2 s4;
    s4 = s2 + s3; // (s2+s3 returns a new obeject, which gets copied in s4)

    std::cout << "after addition" << std::endl;
    s4.display();
    
    return 0;
}
