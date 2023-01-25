#include <bits/stdc++.h>
using namespace std;
int main(){
    string strs; 
    cin>>strs;
    unordered_map<char, int> mp ; 
    for (int  i=0 ; i < strs.size(); i++){
        mp[ strs[i]]++;
    }
vector<char> v1= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char sml[26];
for (char c = 'a'; c <= 'z'; c++) {
    sml[c - 'a'] = c;
}
char cap[26];
for (char c = 'A'; c <= 'Z'; c++) {
    cap[c - 'A'] = c;
}
for( auto m:cap )cout<<m;
    
    for (auto s: mp){
        cout<<s.first;
    }
    return 0; 
}