#include<bits/stdc++.h>
using namespace std;
int main(){
    int n =10;
    vector<int>v{n,0};
    v[1]=1;
    v[2]=2;
    v[3]=3;
    v[4]=4;
    for(int i = 5;i<=n;i++){
        v[i] = v[i-1]+v[i-2]+v[i-3]+v[i-4];
    }
    cout<<v[n]<<endl;
    return 0;
}