#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,int> m1;
    m1["sush"]= 100;
    m1["allen"] = 98;
    m1["louis"] =97;
    map<string,int> :: iterator iter;
    for(iter = m1.begin();iter!=m1.end();iter++){
        cout<<(*iter).first<<"__"<<(*iter).second<<endl;
    }
    return 0;
}