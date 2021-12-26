#include <iostream>
using namespace std;


class node {
    public:
    int data;
    node*next;
    node*prev;

    node (int val)
    {
    data = val;
    next = NULL;
    prev = NULL;
    }
};

void insertathead(node*&head, int val){
    node*n = new node(val);
    n->next = head;
    if (head==NULL){
        head = n;
    }
    n->prev = NULL;
    n->next->prev = n;
    head = n;

}
void insertattail(node*&head,int val){
        node*n = new node(val);
        node*temp =head;
        if (head == NULL){
        head = n;
        return;
    }
        while(temp->next!=NULL){
        temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        

 }

void display(node*head){
    node*temp = head;
    cout<<endl<<"Linked List is created as : ";
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    
} 


void deletehead(node*&head){
    if (head == NULL){
        return;

    }
    node*todelete = head;
    head = head->next;
    head->prev = NULL;
    cout<<endl<<"  head of the linked list had been deleted  "<<endl;
    delete todelete;
}
void deleteele(node*head,int ele){

    node*temp = head;
    if (head== NULL){
        return;
    }
    if(head->next==NULL)
    {
        deletehead(head);
    }
    while(temp->next != NULL && temp->next->data != ele){
        temp = temp->next;

    }
    node*todelete = temp->next;
    temp->next = temp->next->next;
    temp->next->next->prev=temp;
    delete todelete;

}

void displayreverse(node*head){
    node*temp = head;
    cout<<endl<<"Linked List is created as : ";
    while(temp->next!=NULL){
        temp = temp->next;
    }
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->prev;
    }
}

int main(){

    node*head = NULL;


    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    insertattail(head,7);
    insertattail(head,8);
    display(head);
    cout<<endl<<"head->next->prev->data  "<<head->next->prev->data<<" head->data  "<<head->data;
    displayreverse(head);
    deleteele(head,4);
    display(head);
    deletehead(head);
    display(head);
    return 0;
}