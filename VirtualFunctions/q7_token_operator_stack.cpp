#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstring>

class Token {
public:
    virtual float getNumber() = 0;
    virtual char getOperator() = 0;
    virtual ~Token() {}
};

class Operator : public Token {
    char oper;
public:
    Operator(char c) : oper(c) {}
    char getOperator() override { return oper; }
    float getNumber() override { return 0; }
};

class Number : public Token {
    float fnum;
public:
    Number(float ff) : fnum(ff) {}
    float getNumber() override { return fnum; }
    char getOperator() override { return '\0'; }
};

int precedence(char c) {
    switch (c) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return -1;
    }
}

int main() {
    std::stack<Operator*> op;
    std::stack<Number*> nm;
    

    const char* expr = "3.14 + 5 - 2 * 10 / 2 + 7";
    int len = strlen(expr);
    std::string currentNum;

    for (int i = 0; i < len; ++i) {
        char ch = expr[i];

        if (std::isspace(ch)) continue;

        if (std::isdigit(ch) || ch == '.') {
            currentNum += ch;
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            nm.push(new Number(std::stof(currentNum)));
            currentNum.clear();

            while (!op.empty() && precedence(ch) <= precedence(op.top()->getOperator())) {
                auto rhs_ptr = nm.top(); nm.pop();
                auto lhs_ptr = nm.top(); nm.pop();
                auto operand_ptr = op.top(); op.pop();

                float a = lhs_ptr->getNumber();
                float b = rhs_ptr->getNumber();
                char o = operand_ptr->getOperator();

                float result = 0;
                switch (o) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/': result = a / b; break;
                }
                nm.push(new Number(result));
            }
            op.push(new Operator(ch));
        }
    }

    // Push the last number
    if (!currentNum.empty()) {
        nm.push(new Number(std::stof(currentNum)));
    }

    // Final evaluation
    while (!op.empty()) {
        auto rhs_ptr = nm.top(); nm.pop();
        auto lhs_ptr = nm.top(); nm.pop();
        auto operand_ptr = op.top(); op.pop();

        float a = lhs_ptr->getNumber();
        float b = rhs_ptr->getNumber();
        char o = operand_ptr->getOperator();

        float result = 0;
        switch (o) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
        }
        nm.push(new Number(result));
    }

    std::cout << "Result = " << nm.top()->getNumber() << std::endl;

    // Optional cleanup
    while (!nm.empty()) { delete nm.top(); nm.pop(); }
    while (!op.empty()) { delete op.top(); op.pop(); }

    return 0;
}
