#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* link;
    Node(int val){
        data = val;
        link = nullptr;
    }
};
void display (Node* first){
    Node* p = first;
    while (p)
    {
    cout<< p-> data<< "->";
    p = p->link;
    }
    cout<<"NULL";

};
void deleteatstart(Node* first){
    Node* p= first;
    p->link = NULL;
    delete p;
}
int main (){
    Node* n1 = new Node(20);
    Node* n2 = new Node(35);
    Node* n3 = new Node(45);
    Node* n4 = new Node(11);
    n1 ->link = n2;
    n2 ->link = n3;
    n3 ->link = n4;
    display(n1);
    cout<<endl;
    deleteatstart(n1);
    display(n2);
}