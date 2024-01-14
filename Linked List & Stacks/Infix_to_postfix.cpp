#include <bits/stdc++.h>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0; // If the character is not an operator
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    stack<char> operators;
    string postfix;

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch; // If it's an operand, add it to the postfix expression
        } else if (ch == '(') {
            operators.push(ch); // If it's an open parenthesis, push it onto the stack
        } else if (ch == ')') {
            // Pop operators from the stack and add to the postfix expression until an open parenthesis is encountered
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // Remove the open parenthesis from the stack
        } else if (isOperator(ch)) {
            // Pop operators from the stack and add to the postfix expression while they have higher or equal precedence
            while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch); // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack and add to the postfix expression
    while (!operators.empty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> operands;

    for (char ch : postfix) {
        if (isalnum(ch)) {
            operands.push(ch - '0'); // Convert char to int and push operands onto the stack
        } else if (isOperator(ch)) {
            // Pop two operands from the stack, perform the operation, and push the result back onto the stack
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (ch) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }

    // The final result is at the top of the stack
    return operands.top();
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    // Convert infix to postfix
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
