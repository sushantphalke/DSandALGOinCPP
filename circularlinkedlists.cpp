#include<iostream>
using namespace std;

class node {
    public:
     int data;
     node*next;

     node(int val){
         data = val;
         next = NULL;
     }
};

void insertathead(node*&head ,int val){
    node*n = new node(val);
    n->next = head;
    head = n;
    if (head == NULL){
        head = n;
        return;
    }


}

void insertafternode(node*&head ,int after, int val){
    node*n = new node(val);
    node*temp = head ;
    while(temp->data!= after){
        temp=temp->next;
    }
    n->next = temp->next;
    temp->next = n; 


}

void insertattail(node*&head, int val){
    node*n = new node(val);
    node*temp = head;

    if (head == NULL){
        head = n;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;


}

void makecircular(node*&head){
    node*temp=head;
    while (temp->next!=NULL){
        temp=temp->next;

    }
    temp->next=head;
}


void deleteheadofcll(node*&head){
    node*temp = head;
    while (temp->next!=head)
    {
        temp=temp->next;
    }
    node*todelete=head;
    temp->next= head->next;
    head = head->next;
    delete todelete;  
}

void deletetailofcll(node*&head){
    node*temp = head;
    while (temp->next!=head){
        temp = temp->next;
    }
    node*todelete = temp;
    temp->next=head;
    delete todelete;
}
void deleteeleofcll(node*&head,int val){
     if (head == NULL){
        return;
    }

    if(head->next==NULL && head->data ==val){
        deleteheadofcll(head);
    }

    node*temp = head;
    while(temp->next->data != val ){
        temp = temp->next;
        }
    if (temp->next == head){
        deletetailofcll(head);
    }

    node*todelete = temp->next;
    temp->next = temp->next->next;
    cout<<endl<<"  element : "<<val<<"   of circular linked list had been deleted  "<<endl;
    delete todelete;


}


void displaycircularll(node*head){
    cout <<endl<<" circular linked list is created as follows : ";
    node*temp = head;
    do {
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    while(temp != head);
    cout<<"NULL"<<endl;
    cout<<endl;


}



int main (){
    node*head = NULL;
        
        int arr[] = {1,2,3,4,5};
        for (int i=0 ;i<5 ; i++){
            insertattail(head,arr[i]);
        }
        makecircular(head);
        displaycircularll(head);
        deleteheadofcll(head);
        displaycircularll(head);

    return 0;
}