// Making LinkedList using C++ with help of class 
// Also insertatstart, insertatend, insertbefore
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

void display (Node* head){
    Node* p = head;
    while (p)
    {
    cout<< p-> data<< "->";
    p = p->next;
    }
    cout<<"NULL";

};
Node* insertatstart(Node* head,int x){
    Node *n5=new Node(x);
    n5->next=head;
    return n5;
}
void insertatend(Node* head,int y){
    Node *n6 = new Node(y);
    Node* p = head;
    while (p->next!=NULL)
    {
       p=p->next;
    }
    p->next=n6;
    
}
    void  insertbefore(int x,int y,Node* head){
    Node* p = head;
    Node* x1 = new Node(y);
    while(p->next->data!=x && p->next!=NULL){
        p = p->next;
    }
    if(p->next == NULL)
        return;
    x1 ->next = p ->next;
    p->next = x1;
    }
int main (){
    Node* n1 = new Node(20);
    Node* n2 = new Node(30);
    Node* n3 = new Node(40);
    n1 ->next = n2;
    n2 ->next = n3;
    display(n1);
    cout<<endl;
    Node* z= insertatstart(n1,99);
    display(z);
    cout<<endl;
    insertatend(z,101);
    display(z);
    cout<<endl;
    insertbefore(30,105,z);
    display(z);
}