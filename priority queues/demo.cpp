#include<bits/stdc++.h>
using namespace std;

int main(){

    priority_queue<int,vector<int>,greater<int>>q;
        q.push(1);
        q.push(34);
        q.push(33);
        q.push(32);
        

        while(!q.empty()){
            cout<<"--> "<<q.top()<<endl;
            q.pop();
        }


    return 0;
}