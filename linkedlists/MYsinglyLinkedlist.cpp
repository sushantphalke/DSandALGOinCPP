//ACESP's
#include<iostream>
using namespace std;



class node {

    public:

     int data ;
     node*next;
    
     node(int val){
    
         data = val ;
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


bool serching(node*&head , int key){

    node*temp =head ;
    while (temp->next !=NULL ){
        if (temp->data ==key){
            cout <<endl<< " your searched element : "<<key<<"  _is in linked list. "<<endl;
            return true ;
        }
       temp = temp->next;
    }
    cout <<endl<< " your searched element: "<<key<<"_is NOT FOUND in linked list. it either deleted or not in list "<<endl;
    return false;


}


void deletehead(node*&head){

    if (head == NULL){
        return;
    }
     node*todelete=head;
     head = head->next;
     cout<<endl<<"  head of the linked list had been deleted  "<<endl;
     delete todelete;


}


void deletenode(node*&head , int val){
    
    if (head == NULL){
        return;
    }

     if(head->next==NULL && head->data ==val){
        deletehead(head);
    }

    node*temp = head;
    while(temp->next->data != val ){
        temp = temp->next;
        }

    node*todelete = temp->next;
    temp->next = temp->next->next;
    cout<<endl<<"  element : "<<val<<"   of linked list had been deleted  "<<endl;
    delete todelete;


}


void replacenode(node*&head ,int shouldreplace, int val){
    node*temp = head ;
    while(temp->data!= shouldreplace){
        temp=temp->next;
    }
    temp->data =val;


}


node* reverselist(node*&head){
    
    node*previousptr = NULL;
    node*currentptr = head;
    node*nextptr;

    while(currentptr != NULL){

        nextptr = currentptr->next;
        currentptr->next= previousptr;

        previousptr = currentptr;
        currentptr = nextptr;

    }
     return previousptr;

//  O(n) time complexity
}


node* reverseRecursive(node* &head){

    if(head == NULL || head->next==NULL){
        return head;
    }

    node*nhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return nhead;

// O(n) time complexity
}

node* reversek(node*&head , int k){

    node*prevptr= NULL;
    node*currptr = head;
    node*nextptr;

    int count =0;

    while (currptr !=NULL && count <k){

        nextptr = currptr->next;
        currptr->next=prevptr ;
        prevptr = currptr;
        currptr = nextptr;
        count++;

    }
    if(nextptr != NULL){

       head->next = reversek(nextptr,k);

    }
    return prevptr;

// at O(n)time complexity

}

int length(node*head){

    int l =0 ;
    node*temp = head;
    while(temp!=NULL){
        temp = temp->next;
        l++;

    }
    return l;
}

node* atendfirstknodes(node*&head , int k){
    
    node*temp = head;
    node*newHead;
    node*newTail;

    int count =1;
    int l = length(head);
    k = k%l;
    if(k!=0){
        while (temp->next !=NULL && count<k )
        {
            temp= temp->next;
            count++;
        }
        newHead = temp->next;
        newTail = temp;

        node*temp2 = newHead;
        
        while(temp2->next!=NULL){
            temp2=temp2->next;
            }
        temp2->next=head;
        newTail->next = NULL;
    }
    else
    return head;
return newHead;

// at O(n)time complexity
}

node* frontendlastknodes(node*&head,int h){
    
    int p=length(head);
    h=h%p;
    int m=p-h;
    cout<<"linked list by movinrg last :"<<h<<" nodes to front ";
    node*  newH= atendfirstknodes(head,m);

    return newH;
}

void evenposnodesafteroddpos(node*&head){
        node* temp = head;
        node* odd = head;
        node* even = head->next;
        node* evenstart = even;

        while (odd->next!=NULL && even->next!=NULL ){
       
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;

        
        }
           odd->next = evenstart;
            
        if (odd->next!=NULL){

                even->next =NULL;
        }


}

node* merge(node*&head1,node*&head2){
    node* p1 = head1;
    node* p2 = head2;
    node*dummyNode = new node(-1);
    node* p3 = dummyNode;;

    while(p1!=NULL && p2!=NULL){

        if (p1->data<p2->data){
            p3->next = p1;
            p1 = p1->next;

        }
        else {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
        }
        while(p1!=NULL){
            p3->next = p1;
            p1 = p1->next;
            p3= p3->next;

        }
        while(p2!=NULL){
            p3->next = p2;
            p2 = p2->next;
            p3=p3->next;
        }
    
    return dummyNode->next;
}
node* intersect(node*&head1, node*&head2, int pos){

    node*temp1 = head1;
    pos--;
    while (pos--){
        temp1 = temp1->next;

    }
    node* temp2 = head2;
    while(temp2->next!=NULL){
        temp2= temp2->next;

    }

    temp2->next =temp1;
    return head2; 

}


int  intersection(node*&head1 ,node*&head2){
    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node* ptr1;
    node* ptr2;

    if (l1>l2){
        d = l1-l2;
        ptr1 =head1;
        ptr2 =head2;
    }
    else{
        d= l2-l1;
        ptr1 = head2;
        ptr2 = head1;

    }
    
    while(d){
        ptr1 = ptr1->next;
        if (ptr1==NULL){
            return -1;

        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if (ptr1 == ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

    }
    return -1;


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

void display(node*head){
    cout <<endl<<" linked list is created as follows : ";
    node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<endl;


}

/**************************************************** MAIN FUNCTION ****************************************************/

int main(){
        node*head = NULL;
        
        
        insertathead(head,44);
        insertathead(head,45);
        insertathead(head,46);

        insertafternode(head,46,47);

        insertattail(head,43);
        insertattail(head,42);
        insertattail(head,41);
        insertattail(head,40);       
        
        serching(head,46);

        replacenode(head,46,55);
        display(head);
        cout<<"length of linked list is :"<<length(head);
        deletenode(head, 42);

        deletehead(head);

        display(head);

        node*newhead = reverselist(head);
        cout<<"reversed linked list is : ";
        display(newhead);

        node*nhead = reverseRecursive(newhead);
        cout<<"reversed linked list by recursive method :";
        display(nhead);

        int k= 3;
        node*rkhead = reversek(nhead,k);
        cout<<"linked list with reversed : "<<k<<" nodes ";
        display(rkhead);
        

        int g = 2;
        cout<<"linked list by movinrg first :"<<g<<" nodes to tail ";
        node*  newHead= atendfirstknodes(rkhead,g);
        display(newHead);

        int h = 2;
        cout<<"linked list by movinrg last :"<<h<<" nodes to front ";
        node*  newH=  frontendlastknodes(newHead,h);
        display(newH);

        cout<<"Linked List by making all even position nodes after odd position: "<<endl;
        evenposnodesafteroddpos(newH);
        display(newH);

        node*head1=NULL;
        int arr[] = {1,2,33,45,55};
        for (int i=0 ;i<5 ; i++){
            insertattail(head1,arr[i]);
        }
        cout<<" merged Linked List  "<<endl;
        node* newHEAD = merge(newH,head1);
        display(newHEAD);

        node*head3=NULL;
        
        int arr1[] = {1,2,3,4,5};
        for (int i=0 ;i<5 ; i++){
            insertattail(head3,arr1[i]);
        }
        node*head4=NULL;
        int arr2[] = {11,22,33,44};
        for (int i=0 ;i<4 ; i++){
            insertattail(head4,arr2[i]);
        }
        node*head5 = intersect(head3,head4,2);
        display(head5);
        cout<<"intersectionn point of linked list is : ";
        cout<<intersection(head3,head4)<<endl;

        node*head6=NULL;
        
        int arr6[] = {1,2,3,4,5};
        for (int i=0 ;i<5 ; i++){
            insertattail(head6,arr6[i]);
        }
        makecircular(head6);
        displaycircularll(head6);
        deleteheadofcll(head6);
        displaycircularll(head6);
        // node*head7=NULL;
        // int arr7[] = {11,22,33,44};
        // for (int i=0 ;i<4 ; i++){
        //     insertattail(head7,arr7[i]);
        // }
        


    return 0;

}//ACESP's 