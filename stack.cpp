
#include<bits/stdc++.h>
using namespace std;
#include<stack>
#include<queue>


/* implementing stack using arrays */

// #define n 100
// class stack {
//     int*arr;
//     int top;

//     public:
//     stack(){
//         arr=new int[n];
//         top=-1;
//     }


// void push(int x){
//         if (top == n-1){
//             cout<<"stack overflowed"<<endl;
//             return;
//         }
//         top ++;
//         arr[top] = x;
// }

// void pop(){
//     if (top == -1){
//         cout<<"no element to pop"<<endl;
//     return;

//     }
//     top--;
    

// }

// int Top(){
//     if (top==-1){
//         cout<<"no element to pop"<<endl;
//     return 1;}

//     return arr[top] ;
// }
// };
void insertatbottom(stack<int>&st ,int ele){
    if (st.empty()){
      st.push(ele);
        return;
    }
        int topele = st.top();
        st.pop();
        insertatbottom(st,ele);
        st.push(topele);
}
void reverse(stack<int> &st){
    if (st.empty()){
        return; 

    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertatbottom(st,ele);
    
}
int main(){


 stack<int> st;
 queue<int> q;
 q.push(44);
 q.push(12);
 while(!q.empty()){
 cout<<q.front();
 q.pop();
 }
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
//     cout<<st.top()<<"top"<<endl;
//     st.pop();
//     st.pop();
//         cout<<st.top()<<"top"<<endl;
//     st.pop();
//     st.pop();
//     st.pop();
//     st.pop();
//     st.pop();
//     ;
    
    // stack<string> st;
    
    // string s = "hey, how are you doing?";
    
    // for (int i =0 ; i<s.length();i++){
    //     string word = "";
    //     while(s[i]!=' '&&i<s.length()){
    //         word += s[i];
    //         i++;

    //     } 
    //     st.push(word);
    // }
   reverse(st);
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();

            }
        cout<<endl;
    

       
    return 0;  

}
