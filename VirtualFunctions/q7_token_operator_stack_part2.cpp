/*  Parsing using a Token Approach   */

#include<iostream>
#include<vector>
#include<stack>
#include<cstring>

// abstract class
class Token
{
    public:
    virtual float getNumber()=0;
    virtual char getOperator()=0;

    virtual ~Token(){};
};



class Operator : public Token
{
 char oper;

 public:
 Operator(char s): oper(s){}

 char getOperator()
 {
    return oper;
 }

 float getNumber()
 {
    return 0;
 }

 ~Operator(){};

};



class Number : public Token
{

    float fnum;

    public:
    Number(float ff):fnum(ff){}

    float getNumber()
    {
        return fnum;
    }

    char getOperator()
    {
        return '\0';
    }

    ~Number(){};

};


// --- Precedence ---
int precedence(const char cc)
{
    switch(cc)
    {
        case '+': return 1;break;
        case '-': return 1;break;
        case '*': return 2;break;
        case '/': return 2;break;
        default: return -1;
    }

}

// --- MAIN ---
int main()
{

 // Vector to hold pointers to classes Number and Operator
 std::vector<Token* > token_vector;

 // 2 stacks Operator and Number
 std::stack<Operator* > op;
 std::stack<Number* > num;

 // to evaluate
 std::string expr = "3.14 + 2 * 5 - 1 + 10 / 2 * 3 - 1 + 2.55";
 
 // returns a const char* from the string 
 const char* ss = expr.c_str();
 
 int len = strlen(ss);
 //std::cout << len << std::endl;
 
 std::string current_num;
 int x=0;
 while(x<len)
 {
    char ch = ss[x];

    if(std::isspace(ch))
    {   
        x++;
        continue;
    }
    else if(std::isdigit(ch) || ch=='.')
    {
        current_num+=ch;   
    }
    else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        // push the current number token before operator if present
        if(!current_num.empty())
        {
            Number* nn = new Number(std::stof(current_num));
            token_vector.push_back(nn);
            current_num.clear(); // push it in the vector and not the stack Number
        }
        // create and push the operator token
        Operator* oo = new Operator(ch);
        token_vector.push_back(oo);
    }
    else
    {
        std::cout << "unknown character !" << std::endl;
    }

 x++;
 
}// end of while, we have created a vector of stack pointers

 // push the Number pointer in the token vector
 if(!current_num.empty())
 {
    Number* nn = new Number(std::stof(current_num));
    token_vector.push_back(nn);
    current_num.clear();
 }

 // -- Logic : read the vector and make the calculations --
 // token_vector has pointers to the class Number and Operator
 // stack operations will be done from here...

 for(auto x : token_vector)
 {
    // instead of evalauting the string now use the same logic to evaluate the vector, reading out pointers.
    Number* num_ptr = dynamic_cast<Number*>(x);
    if (num_ptr)
    {
        // push the number pointer on the Numbers stack
        num.push(num_ptr);
    }

    Operator* op_ptr = dynamic_cast<Operator*>(x);
    if(op_ptr)
    {    
        // compare the operator in vector to the one in the Operator stack
        if (!op.empty() && precedence(op_ptr->getOperator()) <= precedence(op.top()->getOperator()))

        {
            auto rhs = num.top(); num.pop(); // rhs is a pointer
            auto lhs = num.top(); num.pop(); // lhs is a pointer
            auto oper = op.top(); op.pop();  // oper is a pointer
            
            float result;
            switch(oper->getOperator())
            {
                case '+': { 
                            result=lhs->getNumber() + rhs->getNumber();
                            
                            break;
                        }

                case '-': { 
                            result=lhs->getNumber() - rhs->getNumber();
                            
                            break;
                          }

                case '*': {
                            
                            result=lhs->getNumber() * rhs->getNumber();
                            
                            break;
                        }

                case '/': { 
                            result=lhs->getNumber() / rhs->getNumber();
                        
                            break;
                        }

            }// push the result on the stack
            Number* r = new Number(result);
            num.push(r);

        }
        // push the operator pointer on the Operators stack
        op.push(op_ptr);
    }

 }


 // pop all operators
 while(!op.empty())
 {
    auto rhs = num.top();num.pop();
    auto lhs = num.top();num.pop();
    auto oo  = op.top();op.pop();

    float y = rhs->getNumber();
    float x = lhs->getNumber();
    char opr = oo->getOperator();
    
    float result;
    switch(opr)
    {
        case '+':
        {
             result = x+y;
           
            break;
        }

        case '-': 
        {
            result = x-y;
           
            break;
        }

        case '*': 
        {
            result = x*y;
            ;
            break;
        }

        case '/':
        {
            result = x/y;
        
            break;
        }
    }
     Number* r = new Number(result);
     num.push(r);
 }

 std::cout << "final result is: " << num.top()->getNumber() << std::endl;


 // cleanup
 while(!num.empty())
 {
    delete num.top(); num.pop();
    
 }

 while(!op.empty())
 {
    delete op.top(); op.pop();
 }
 return 0;
}