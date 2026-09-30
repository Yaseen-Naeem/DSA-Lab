#include <iostream>
#include <string>
using namespace std;

//  Part A)
struct Node{
    string url;
    Node* next;

    Node(string u){
        url = u;
        next = NULL;
    }
};

class BrowserHistory{
    public:
    Node* top;

    BrowserHistory(){
        top = NULL;
    }

    // Part B)
    void visit(string url){
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;

        cout << "Now at: " << url << endl;
    }

    // Part C)
    void goBack(){
        if(top == NULL || top->next == NULL){
            cout << "No previous page in history" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;

        delete temp;
        cout << "Back to: " << top->url << endl;
    }

    // Part D)
    string currentPage(){
        if(top == NULL){
            return " ";
        }

        return top->url;
    }
};

int main(){
    BrowserHistory browser;

    browser.visit("google.com");
    browser.visit("github.com");
    browser.visit("docs.com");

    browser.goBack();
    browser.goBack();
    browser.goBack();

    return 0;
  
  
}