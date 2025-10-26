
#include<iostream>
#include<stack>
#include<vector>

int precedence(const char c)
{
    if (c=='+' || c=='-') {return 1;}
    else if(c=='*' || c=='/') {return 2;}
    else {std::cout<<"wrong operator"<<std::endl; return -1;}
}


int main()
{
 
 std::stack<char>  op;
 std::stack<float> nm;

 const char* expr = "3.14 + 4.05 * 5 - 1 + 10/2 +1";
 
 int len = strlen(expr);
 
 std::string number; 
 
 int i=0;
 while(i<len)
 {
    //std::cout << expr[i] << " ";
      
    char ch;
    ch = expr[i];

    if(std::isspace(ch))
    {
        i++;
        continue;
    }
    else if(std::isdigit(ch) || ch == '.')
    {
        //build the number
        number+=ch;
    }
    else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        //put the number on the numbers stack
        nm.push(std::stof(number));
        number.clear();

        while(!op.empty() && precedence(op.top())>=precedence(ch))
        {
            char c = op.top();op.pop();
            float b = nm.top(); nm.pop(); // first pop is right operand
            float a = nm.top(); nm.pop();
            
            switch(c)
            {
                case '+': nm.push((a+b)); break;
                case '-': nm.push((a-b)); break;
                case '/': nm.push((a/b)); break;
                case '*': nm.push((a*b)); break;
            }
            
        }

        op.push(ch);
        

    }
    
    i++;
 }// end of while

  // push last number on stack
  if (!number.empty()) {
        nm.push(std::stof(number));
    }

 // pop all operators
 while(!op.empty())
 {
    float y = nm.top(); nm.pop(); // first pop is right operand
    float x = nm.top(); nm.pop();
    char c = op.top(); op.pop();
    switch(c)
    {
        case '+': nm.push(x+y); break;
        case '-': nm.push(x-y); break;
        case '/': nm.push((x/y)); break;
        case '*': nm.push((x*y)); break;
    }
 }

 std::cout << "final answer: "<<nm.top() << std::endl;

 return 0;
}