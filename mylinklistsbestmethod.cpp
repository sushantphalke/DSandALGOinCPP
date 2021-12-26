//ACESP's


#include <iostream>
using namespace std ;


class node {
    public:

    int data;
    node * next ;
    node (int val)
    {
        data = val;
        next = NULL ;
    }
};


void insertattail(node* &head , int val){
    
    node*n = new node(val);
    node* temp = head;
    if (head == NULL) {
        head =n;
        return;
    }   
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
}


void insertatbeginning(node* &head,int val){

    node*n = new node(val);
    n->next = head;
    head = n;
}


bool serching(node*head , int key){

    node*temp =head ;
    while (temp->next !=NULL ){
        if (temp->data ==key){
            cout << "your searched element : "<<key<<"  _is in linked list. "<<endl;
            return true ;
        }
       temp = temp->next;
    }return false;
}


void deletehead(node*&head){

    if (head == NULL){
        return;
    }
     node*todelete=head;
     head = head->next;
     cout<<"  head of the linked list had been deleted  "<<endl;
     delete todelete;
}


void deleteelement(node*&head ,int val){

    if (head == NULL){
        return;
    }
    if(head->next==NULL){
        deletehead(head);
    }
    node*temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
        node*todelete=temp->next;
        temp->next=temp->next->next;
        cout<<"  element : "<<val<<"   of linked list had been deleted  "<<endl;
        delete todelete;
}


void display( node*head){

     cout <<"linked list is created as follows : ";
      node* temp =head;
      while(temp != NULL){
         cout <<temp->data << " ";
         temp=temp->next;
      }
      cout << endl;
}

 


int main(){

    node*head = NULL ;
    

    insertattail(head,1);
    insertattail(head,2);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,6);
    insertattail(head,7);
    insertattail(head,8);
    insertattail(head,9);
    insertattail(head,10);
    insertattail(head,11);
    insertattail(head,12);
   
    insertatbeginning(head , 0);

    display(head);

    deleteelement(head,4);
    deletehead(head);

    serching(head, 5);
    cout << serching(head,7)<<endl; //if we give cout at begining then it will additionaly shows output in form of 0 or 1 because we get return value from code.
  
    cout << "updated ";
    display(head);

    return 0 ;
    
}//ACESP's