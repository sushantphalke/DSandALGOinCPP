#include<bits/stdc++.h>
using namespace std;
           
int main(){
      int n,x,y;
      cin>>n>>x>>y;
      vector<int> arr1(n),arr2(n);
      for(int i=0;i<n;i++){
          cin>>arr1[i];
      }
      for(int i=0;i<n;i++){
          cin>>arr2[i];
      }
      int i=0,j=0;
      int sc = 0;
      while(x>0 && y>0){
        if(arr1[i] > arr2[i]){
            sc += arr1[i];
            i++;
            x--;
        }
        else{
            sc+=arr2[i];
            j++;
            y--;
        }
      }
      while(x>0){
            sc += arr1[i];
            i++;
            x--;
      }
      while(y>0){
            sc+=arr2[i];
            j++;
            y--;
      }
      cout<<sc<<endl;
  return 0;
}

// wrong code