#include <bits/stdc++.h>
using namespace std;
 
void subseq(int ind,vector<int>arr,vector<int>&ds,int n){
    if(ind==n){
        for(auto i: ds) cout<<i<<" ";
        if(ds.size()==0)cout<<"{}";
        cout<<endl;
    }
    if(ind>=n)return;
    subseq(ind+1,arr,ds,n);

    ds.push_back(arr[ind]);
    subseq(ind+1,arr,ds,n);
    ds.pop_back();

}

int main(){
    

    vector<int>arr ={3,1,2};
    vector<int>ds;
    subseq(0,arr,ds,arr.size());


    return 0;
}