#include <iostream>
#include <string>
using namespace std;

class Stack{
    public:
    char arr[100];
    int top;

    Stack(){
        top = -1;
    }

    void push(char ch){
        arr[++top] = ch;
    }

    char pop(){
        return arr[top--];
    }

    char peek(){
        return arr[top];
    }


    bool isEmpty(){
        return top == -1;
    }
};

int precedence(char op){
    if(op == '^')
        return 3;

    else if(op == '*' || op == '/')
        return 2;

    else if(op == '+' || op == '-')
        return 1;

    return 0;
}

bool isOperator(char ch){
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/' || ch == '^';
}

bool isBalanced(string exp){
    Stack s;

    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == '(')
            s.push('(');

        else if(exp[i] == ')'){
            if(s.isEmpty())
                return false;

            s.pop();
        }
    }

    return s.isEmpty();
}

string infixToPostfix(string exp){
    Stack s;
    string result = "";

    for(int i = 0; i < exp.length(); i++){
        char ch = exp[i];

        if(isalnum(ch)){
            result += ch;
        }

        else if(ch == '('){
            s.push(ch);
        }

        else if(ch == ')'){
            while(!s.isEmpty() && s.peek() != '('){
                result += s.pop();
            }
            s.pop();
        }

        else if(isOperator(ch)){
            while(!s.isEmpty() &&
                  s.peek() != '(' &&
                  precedence(s.peek()) >= precedence(ch)){
                if(ch == '^')
                    break;
                result += s.pop();
            }

            s.push(ch);
        }

    }

    while(!s.isEmpty()){
        result += s.pop();
    }

    return result;
}

int main(){
    string exp;

    cout << "Enter infix expression: ";
    cin >> exp;

    if(!isBalanced(exp)){
        cout << "Invalid Expression" << endl;
    }
    else{
        cout << "Postfix: " << infixToPostfix(exp) << endl;
    }

 
    return 0;
}