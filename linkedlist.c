// Making LinkedList using C lang with the help of struct 
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;  
};
void display(struct Node* head){
    while (head!=NULL)
    {
       printf("%d\n",head->data);
       head = head->next;
    }
}
int main(){
    struct Node * n1;
  n1 = (struct Node*)malloc(sizeof (struct Node));
  n1->data = 20;
 struct Node * n2;
 n2 = (struct Node*)malloc(sizeof (struct Node));
 n2->data = 99;
 struct Node * n3 = (struct Node*)malloc(sizeof (struct Node));
 n3->data = 30;
n1->next=n2;
n2->next=n3;
n3->next=NULL;
struct Node* temp=n1;
display(temp);
    return 0;
}
