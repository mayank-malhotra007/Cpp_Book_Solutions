
#include <iostream>
#include <iomanip>

class Sterling {
    long pounds;
    int shillings;
    int pence;

    void normalize() {
        if (pence >= 12) {
            shillings += pence / 12;
            pence %= 12;
        }
        if (shillings >= 20) {
            pounds += shillings / 20;
            shillings %= 20;
        }

        // handle negatives properly
        if (pence < 0) {
            pence += 12;
            shillings--;
        }
        if (shillings < 0) {
            shillings += 20;
            pounds--;
        }
    }

public:
    Sterling(): pounds(0), shillings(0), pence(0) {}
    
    Sterling(long p, int s, int d): pounds(p), shillings(s), pence(d) { normalize(); }
    
    Sterling(float f)
    {
        long totalPence = static_cast<long>(f * 240); // convert to pence, round
        pounds = totalPence / 240; // get the full pounds
        shillings = (totalPence % 240) / 12; // remaining are shillings found by % 
        pence = totalPence % 12; // leftover are pences
    }   


    void getSterling() {
        std::cout << "Enter pounds: "; std::cin >> pounds;
        std::cout << "Enter shillings: "; std::cin >> shillings;
        std::cout << "Enter pence: "; std::cin >> pence;
        normalize();
    }

    void putSterling() const {
        std::cout << "£" << pounds << "." << shillings << "." << pence << std::endl;
    }

    // Addition
    Sterling operator+(const Sterling& rhs) const {
        Sterling temp(pounds + rhs.pounds, shillings + rhs.shillings, pence + rhs.pence);
        temp.normalize();
        return temp;
    }

    // Subtraction
    Sterling operator-(const Sterling& rhs) const {
        long total1 = pounds * 240 + shillings * 12 + pence;
        long total2 = rhs.pounds * 240 + rhs.shillings * 12 + rhs.pence;
        long diff = total1 - total2;
        return Sterling(diff / 240, (diff % 240) / 12, diff % 12);
    }


    // Multiplication by a scalar
    Sterling operator*(double rhs) const {
        long totalPence = pounds * 240 + shillings * 12 + pence;
        totalPence = static_cast<long>(totalPence * rhs);
        return Sterling(totalPence / 240, (totalPence % 240) / 12, totalPence % 12);
    }

    
    // Division by a scalar
    Sterling operator/(double rhs) const {
        long totalPence = pounds * 240 + shillings * 12 + pence;
        totalPence = static_cast<long>(totalPence / rhs);
        return Sterling(totalPence / 240, (totalPence % 240) / 12, totalPence % 12);
    }

    // Division Sterling/Sterling (ratio)
    double operator/(const Sterling& rhs) const {
        long total1 = pounds * 240 + shillings * 12 + pence;
        long total2 = rhs.pounds * 240 + rhs.shillings * 12 + rhs.pence;
        return static_cast<double>(total1) / total2;
    }

    // converter
    operator float() const
    {
        return static_cast<float>(pounds + shillings / 20.0 + pence / 240.0);
    }

};

int main() {
    Sterling s1, s2;
    std::cout << "Enter first amount:\n";
    s1.getSterling();
    std::cout << "Enter second amount:\n";
    s2.getSterling();

    std::cout << "\nYou entered:\n";
    s1.putSterling();
    s2.putSterling();

    Sterling s3 = s1 + s2;
    std::cout << "\nAddition: ";
    s3.putSterling();

    Sterling s4 = s1 - s2;
    std::cout << "Subtraction: ";
    s4.putSterling();

    Sterling s5 = s1 * 2.5;
    std::cout << "Multiply by 2.5: ";
    s5.putSterling();

    Sterling s6 = s1 / 3.0;
    std::cout << "Divide by 3: ";
    s6.putSterling();

    double ratio = s1 / s2;
    std::cout << "Ratio s1/s2 = " << ratio << std::endl;

    // conversion operator
    Sterling p(5,10,6);
    float ff = p;
    std::cout << "float: " << ff << std::endl;
    
    return 0;
}
