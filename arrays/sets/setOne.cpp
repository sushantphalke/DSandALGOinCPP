#include<bits/stdc++.h>
using namespace std;


int main(){
set<int> s;
int v =43;

for (int i=0 ;i<v; i++){
s.insert(i);
}
set<int>:: iterator p;
for(p = s.begin();p!=s.end();p++){
    cout<< *p <<endl;

}
auto it = s.lower_bound(33);
auto ite = s.upper_bound(33);
cout<<*ite<<endl;



return 0;

}