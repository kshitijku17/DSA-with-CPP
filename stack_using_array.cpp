// Stack using array. 
#include <iostream>
#define N 5
using namespace std;
int TOS = -1;
int a[N] = {};
void push(int x){
if(TOS == N-1){
cout<<"Stack overflow"<<endl;
return; }
else{
TOS++;
a[TOS] = x;
cout<<a[TOS]<<endl;
}
}
int pop(){
    int y;
if(TOS == -1){
cout<<"Stack underflow"<<endl;}
else{
y = a[TOS];
TOS--;
cout<<y<<endl;
return y;
}
}
int main(){
    cout<<"PUSH output"<<endl;
    push(1);
    push(2);
    push(3);
    push(5);
    cout<<"POP output "<<endl;
    pop();
    pop();
    pop();
}
