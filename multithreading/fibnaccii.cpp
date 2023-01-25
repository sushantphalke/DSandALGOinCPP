#include<bits/stdc++.h>
using namespace std;


int parallel_fib(int n){
    if(n<=1)
    return n ;
    else {
        int x = spawn(parallel_fib(n-1));
        int y = parallel_fib(n-2);
        sync;
        
    }
}

int main(){

    int n; 
    cin>> n ;
    cout<<parallel_fib(n)<<endl;
    return 0;
}