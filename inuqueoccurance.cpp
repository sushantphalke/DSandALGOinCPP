#include<bits/stdc++.h>
using namespace std;


int main(){
    vector <int> arr = {1,2};
    int n = arr.size();
    unordered_map<int, int> mp; 

    for(auto x:arr){
        mp[x]++;
    }
    unordered_map<int,int> v;
    for(auto m : mp){
        v[m.second]++;

    }
    bool flag =true;
    for(auto x:v){
        if(x.second>1)
        flag =false;

    }
    flag?cout<<true:cout<<false;

    




    // return 0;
}