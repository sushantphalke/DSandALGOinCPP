/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>


using namespace std;

string solution(string str){
    map<char,int>m;
    string ans="";
    
    for(int i=0;i<str.size();i++){
        m[str[i]]+=1;
    }
    
    for(int i=0;i<str.size();i++){
        if(m[str[i]]>0){
            ans+=str[i]+to_string(m[str[i]]);
            m[str[i]]=0;
        }
    }
    return ans;
}

int main()
{
    string str="abaabcdabcd";
    
    cout<<solution(str);

    return 0;
}
