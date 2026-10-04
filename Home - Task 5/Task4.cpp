#include <iostream>
#include <string>
using namespace std;

int main(){
    string exp;
    int stack[100];
    int top = -1;
    bool error = false;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++){
        char c = exp[i];

        if (c >= '0' && c <= '9'){
            stack[++top] = c - '0';
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/'){
            if (top < 1){
                error = true;
                break;
            }

            int b = stack[top--];
            int a = stack[top--];
            int result;

            if (c == '+'){
                result = a + b;
                }

            else if (c == '-'){
                result = a - b;
                }

            else if (c == '*'){
                result = a * b;
                }

            else{
                result = a / b;
                }

            stack[++top] = result;
        }

        else{
            error = true;
            break;
        }
    }

    if (error || top != 0){
        cout << "Error: Malformed expression";
        }

    else{
        cout << "Output: " << stack[top];
    }

    return 0;
}