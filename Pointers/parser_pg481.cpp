#include <iostream>
#include <cstring>
#include <cctype>  // for isdigit

const int LEN = 80;
const int MAX = 40;

// Stack for integers
class IntStack {
    int st[MAX];
    int top;
public:
    IntStack() : top(-1) {}
    void push(int val) { st[++top] = val; }
    int pop() { return st[top--]; }
    int peek() { return st[top]; }
    bool isEmpty() { return top == -1; }
};

// Stack for operators
class CharStack {
    char st[MAX];
    int top;
public:
    CharStack() : top(-1) {}
    void push(char ch) { st[++top] = ch; }
    char pop() { return st[top--]; }
    char peek() { return st[top]; }
    bool isEmpty() { return top == -1; }
};

// Helper function: precedence
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Apply operation
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

class Expression {
    char expr[LEN];
public:
    Expression(const char* input) { strcpy(expr, input); }

    int evaluate() {
        IntStack values;
        CharStack ops;
        int len = strlen(expr);

        for(int i = 0; i < len; i++) 
        {
            char ch = expr[i];

            if(ch == ' ') continue; // skip spaces

            if(isdigit(ch)) 
            {
                values.push(ch - '0');
            }
            else if(ch == '+' || ch == '-' || ch == '*' || ch == '/') 
            {
                while(!ops.isEmpty() && precedence(ops.peek()) >= precedence(ch)) {
                    int val2 = values.pop();
                    int val1 = values.pop();
                    char op = ops.pop();
                    values.push(applyOp(val1, val2, op));
                }
                ops.push(ch);
            }
            else {
                std::cout << "Unknown character: " << ch << std::endl;
                return 0;
            }
        }

        // remaining ops
        while(!ops.isEmpty()) {
            int val2 = values.pop();
            int val1 = values.pop();
            char op = ops.pop();
            values.push(applyOp(val1, val2, op));
        }

        return values.pop(); // final value
    }
};

int main() {
    char ans;
    char input[LEN];

    std::cout << "Enter an arithmetic expression (single-digit numbers only, e.g., 2+3*4/2-1)" << std::endl;

    do {
        std::cout << "Expression: ";
        std::cin.getline(input, LEN);

        Expression exp(input);
        std::cout << "Result: " << exp.evaluate() << std::endl;

        std::cout << "Enter another expression? (y/n): ";
        std::cin >> ans;
        std::cin.ignore(); // clear newline left in buffer
    } while(ans == 'y' || ans == 'Y');

    return 0;
}
