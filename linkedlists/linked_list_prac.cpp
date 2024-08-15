#include<bits/stdc++.h>
using namespace std;


class node{
    public:
    int data;
    node* nextAddress; 

    node(int val){
        data = val;
        nextAddress=NULL;
    }
};
int main(){
    // Create a new linked list
    node  *head = new node(1);
    node*second=new node(2);
    head->nextAddress=&second;

    


    cout<<head->data<<endl;
    cout<<second->data<<endl;
}