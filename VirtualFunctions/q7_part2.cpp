
/* Parser */
/*    "3.14 / 2.0 + 75.25 * 3.33 - 6.02"  */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>


int main()
{
  
    std::vector<char> operators;
    std::vector<std::string> numbers;
    std::vector<float> nn;

    std::string ss;

    std::cout << "enter an expression: ";
    std::cin >> ss;

    // provides a null terminated array of char with a pointer to first char.
    const char* p = ss.c_str();

    std::cout << "You entered: " << ss << std::endl;
    
    int x=0;
    std::string num;

    while(x < strlen(p))
    {
        char ch;
        ch = *(p+x);
       
      
        
        if(std::isdigit(ch) || ch=='.')
        {
            num+=ch; // build the number
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        {
            if(!num.empty())
            {
                //x = std::stoi(num);
                numbers.push_back(num);
                num.clear(); // clear the number string
            }
            operators.push_back(ch);
        }
       
      
        x++;
    }

    for(auto x:operators)
    {
        std::cout << x << " ";
    }

    std::cout << std::endl;

    for(auto y:numbers)
    {
        std::cout << y <<" ";
        float x = std::stof(y);
        nn.push_back(x);

    }

    std::cout << std::endl;

    for(auto z:nn)
    {
        std::cout << z <<" ";
        
    }

    std::cout << std::endl;
    return 0;
}