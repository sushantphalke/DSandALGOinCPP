#include<bits/stdc++.h>
using namespace std;

int main(){

   vector<int> arr = {1,1,0,1,1,1};
   int mx=0, prevmx=0;
   int n = arr.size();
   for(int i =0 ; i<n ; i++){
    if(arr[i]==1){
        mx++;
            
    }

    else{
        if(mx>=prevmx){
            prevmx = mx;
        }
        mx=0;
    }
    
   }

   if( mx>prevmx){
    prevmx=mx;
   }

   cout<<prevmx;

    return 0;
}