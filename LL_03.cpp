// LinkedList using Struct
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node*next;
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node* next) : data(data), next(next) {}
};
void display (Node* first){
    Node* p = first;
    while (p)
    {
    cout<< p-> data<< "->";
    p = p->next;
    }
    cout<<"NULL";

};
Node* deleteatstart(Node* first){
    // Node* p= first;
     Node* temp = first;
    first = first->next;
    delete temp;
    return first;
};
Node* deleteatend(Node* first){
    Node* p= first;
    while(p->next->next != nullptr){
        p = p->next;
    }
    Node* temp = p->next;
    p->next = nullptr;
    delete temp;
    return first;
};
Node* deletebefore(Node* head, int x){
        // If list is empty, has only 1 node, or target is the first node (nothing before it)
        if (head == nullptr || head->next == nullptr || head->data == x) {
            return head;
        }

        // Edge Case: If the target 'x' is the second node, we must delete the head
        if (head->next->data == x) {
            Node* temp = head;    
            head = head->next;    
            delete temp;           
            return head;
        }

        // Standard Case: We need to stop TWO nodes before the target 'x'
        Node* q = head;
        while(q->next != nullptr && q->next->next != nullptr && q->next->next->data != x){
            q = q->next;
        }

        // If we found the target two steps ahead
        if (q->next != nullptr && q->next->next != nullptr && q->next->next->data == x) {
            Node* nodeToDelete = q->next;     
            q->next = q->next->next; 
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
    n1 ->next = n2;
    n2 ->next = n3;
    n3 ->next = n4;
    n4 ->next = n5;
    n5 ->next = n6;
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
