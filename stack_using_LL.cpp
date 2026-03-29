// Stack using LinkendList
#include <iostream>
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
            cout<<p->data<<endl;
        }
    };
    int pop(){
        int y;
        if(TOS == NULL){
            cout<<"Stack underflow"<<endl;
        }
        else{
            y = TOS->data;
            Node* p= TOS;
            TOS = TOS->next;
            delete(p);
            cout<<y<<endl;
            return y;
        }
    };

int main (){
    cout<<"PUSH output"<<endl;
    push(3);
    push(5);
    push(1);
    push(6);
    cout<<"POP output "<<endl;
    pop();
    pop();
    pop();
    pop();
    pop();
}