// 
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
Node* head = NULL;
void display (){
    Node* p = head;
    while (p)
    {
    cout<< p-> data<< "->";
    p = p->next;
    }
    cout<<"NULL";

};
int count = 0;
int len(){
    Node* p = head;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
};
// Finding Mid value using Count 
int midnormal(){
    int mid = count/2;
    Node* p = head;
    while(mid--){
        p = p->next;
    }
    return p->data;
};
// finding Mid value using Hare and tortoise algo
int midnew(){
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=nullptr){
        slow = slow->next;
        fast = fast ->next->next;
    }
    return slow->data;
};
// Reveserd of a linkend list 
void rev(){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward;
    while(curr!=NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
};

int main (){
    head = new Node(10);
    Node* n1 = new Node(20);
    Node* n2 = new Node(30);
    Node* n3 = new Node(40);
    Node* n4 = new Node(50);
    Node* n5 = new Node(60);
    head ->next = n1;
    n1 ->next = n2;
    n2 ->next = n3;
    n3 ->next = n4;
    n4 ->next = n5;
    cout<<"Before swapping "<<endl;
    display();

    cout<<"\nAfter swapping "<<endl;
    rev();
    display();

    // int k = len();
    // int c = midnormal();
    // int p = midnew();
    // cout<<"\n len is "<<k<<endl;
    // cout<<"\n mid by normal is "<<c<<endl;
    // cout<<"\n mid is New is "<<p<<endl;
}