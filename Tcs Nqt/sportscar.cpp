#include<bits/stdc++.h>
using namespace std; 
 int main(){
    int n1,n2,x;
    cin>> n1>>n2>>x;
    int first =x;
    int second=0;
    int i=0;

    while(first>second){
        i++;
        first+=n1;
        // cout<<endl<<first;cout<<"i"<<endl;
        second+=n2;
    }
    cout<<i;
    return i;

 }