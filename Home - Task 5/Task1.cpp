#include <iostream>
#include <string>
using namespace std;

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int getPrecedence(char c){
    if (c == '^')
        return 3;

    if (c == '*' || c == '/')
        return 2;

    if (c == '+' || c == '-')
        return 1;

    return 0;
}


bool isBalanced(string exp){
    int count = 0;

    for (int i = 0; i < exp.length(); i++){
        if (exp[i] == '(')
            count++;

        else if (exp[i] == ')'){
            count--;

            if (count < 0)
                return false;
        }
    }

    return count == 0;
}

string infixToPrefix(string exp){
    string reversed = "";
    
    for (int i = exp.length() - 1; i >= 0; i--){
        if (exp[i] == '(')
            reversed += ')';

        else if (exp[i] == ')')
            reversed += '(';

        else
            reversed += exp[i];
    }


    char stack[100];
    int top = -1;
    string result = "";

    for (int i = 0; i < reversed.length(); i++){
        char c = reversed[i];

        if (c >= 'A' && c <= 'Z'){
            result += c;
            }

        else if (c == '('){
            stack[++top] = c;
        }

        else if (c == ')'){
            while (stack[top] != '(')
                result += stack[top--];

            top--;
        }

        else if (isOperator(c)){
            while (top != -1 && stack[top] != '(' &&
                   getPrecedence(stack[top]) > getPrecedence(c)){
                result += stack[top--];
            }

            stack[++top] = c;
        }
    }

    while (top != -1)
        result += stack[top--];

    string prefix = "";

    for (int i = result.length() - 1; i >= 0; i--){
        prefix += result[i];
        }

    return prefix;
}

int main(){
    string exp;

    cout << "Enter expression: ";
    cin >> exp;

    if (isBalanced(exp)){
        cout << "Prefix: " << infixToPrefix(exp);
        }

    else{
        cout << "Unbalanced Parentheses";
        }

    return 0;
}