

#include <iostream>
#include<bits/stdc++.h>


using namespace std;
    bool checkCyclic(string str1,string str2){
        str2=str2+str2;
        string str="";
        int count=0;
        for(int i=0;i<str2.size();i++){
            if(str2[i]==str1[0]){
                for( int j=0;j<str1.size();j++){
                    if(str2[i]==str1[j]){
                        str+=str2[i];
                        ++i;
                    }
                    else
                    break;
                    
                }               
        }
        
       if(str==str1)
         return true;
         
         str="";
        
        }
        
        return false;
    }
    
int main()
{
    string str1="abcd";
    string  str2="cdba";
    
    cout<<checkCyclic(str1,str2);
    return 0;
}

