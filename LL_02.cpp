// Deleting a Node 
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

Node * deleteatstart(Node* first){
    // Node* p= first;
    Node* temp = first;
    first = first->link;
    delete temp;
    return first;
};
Node * deleteatend(Node* first){
    Node* p= first;
    while(p->link->link != nullptr){
        p = p->link;
    }
    Node* temp = p->link;
    p->link = nullptr;
    delete temp;

    return first;
};
Node* deletebefore(Node* head, int x){
        // If list is empty, has only 1 node, or target is the first node (nothing before it)
        if (head == nullptr || head->link == nullptr || head->data == x) {
            return head;
        }

        // Edge Case: If the target 'x' is the second node, we must delete the head
        if (head->link->data == x) {
            Node* temp = head;    
            head = head->link;    
            delete temp;           
            return head;
        }

        // Standard Case: We need to stop TWO nodes before the target 'x'
        Node* q = head;
        while(q->link != nullptr && q->link->link != nullptr && q->link->link->data != x){
            q = q->link;
        }

        // If we found the target two steps ahead
        if (q->link != nullptr && q->link->link != nullptr && q->link->link->data == x) {
            Node* nodeToDelete = q->link;     
            q->link = q->link->link; 
            delete nodeToDelete;  
        }
        
        return head;
};
int main (){
    Node* n1 = new Node(20);
    Node* n2 = new Node(35);
    Node* n3 = new Node(45);
    Node* n4 = new Node(11);
    Node* n5 = new Node(33);
    Node* n6 = new Node(78);
    n1 ->link = n2;
    n2 ->link = n3;
    n3 ->link = n4;
    n4 ->link = n5;
    n5 ->link = n6;
    Node* head = n1;
    cout<<"Original"<<endl;
    display(head);
    cout<<endl;
    cout<<"Delete at start"<<endl;
    head = deleteatstart(head);
    display(head);
    cout<<endl;
    cout<<"Delete before (Egde case)"<<endl;
    head = deletebefore(head,45);
    display(head);
    cout<<endl;
    cout<<"Delete before "<<endl;
    head = deletebefore(head,33);
    display(head);
    cout<<endl;
    cout<<"Delete at end"<<endl;
    head = deleteatend(head);
    display(head);
}
