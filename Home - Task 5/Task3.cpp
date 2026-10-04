#include <iostream>
#include <string>
using namespace std;

int main(){
    string exp;
    char stack[100];
    int top = -1;
    bool balanced = true;

    cout << "Enter expression: ";
    cin >> exp;

    for (int i = 0; i < exp.length(); i++){
        char c = exp[i];

        if (c == '(' || c == '{' || c == '['){
            stack[++top] = c;
        }

        else if (c == ')' || c == '}' || c == ']'){
            if (top == -1){
                balanced = false;
                break;
            }

            char open = stack[top--];

            if ((c == ')' && open != '(') || (c == '}' && open != '{') || (c == ']' && open != '[')){
                balanced = false;
                break;
            }
        }
    }

    if (top != -1){
        balanced = false;
        }

    else if (balanced){
        cout << "Balanced";
        }

    else{
        cout << "Not Balanced";
    }

    return 0;
}