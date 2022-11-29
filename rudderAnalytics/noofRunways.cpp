#include<bits/stdc++.h>
using namespace std;

int maxPlatform(int arr[],int dep[],int n){
    sort(arr,arr+n);
    sort(dep,dep+n);

    int currPlatform=1;
    int maxPlatform=1;

    int i=1,j=0;

    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            currPlatform++;
            i++;
        }
        else if(arr[i]>dep[j]){
            currPlatform--;
            j++;
        }
        maxPlatform=max(maxPlatform,currPlatform);
    }
    return maxPlatform;
}

int main(){
    int n;
    cin>>n;
    int arr[n],dep[n];
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        arr[i] = val;
    }  
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        dep[i] = val;
    }  
          cout<<maxPlatform(arr,dep,6); 
  return 0;
}


