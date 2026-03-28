#include <iostream>
// #define TOS NULL;
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* TOS = nullptr;
    void push(int x){
        Node* p = new Node(x);
        if(p == NULL){
            cout<<"Memory unavaiable"<<endl;
            return;
        }
        else{
            p->data = x;
            p->next = TOS;
            TOS = p;
        }
    };
    int pop(){
        int y;
        if(TOS == NULL){
            cout<<"Stack underflow"<<endl;
            //return;
        }
        else{
            y = TOS->data;
            Node* p= TOS;
            TOS = TOS->next;
            delete(p);
            return y;
        }
    };

int main (){
    push(3);
    push(5);
    push(1);
    push(6);
    cout<< pop()<<endl;
    cout<< pop()<<endl;
    cout<< pop()<<endl;
}