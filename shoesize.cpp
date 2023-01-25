#include <bits/stdc++.h>
using namespace std;
int main(){
    int m, n , o ;
    cin >> m >> n >> o ;
    int k = min(m,n);
    k = min(k,o);
    int fact = 1;
    for (int i =1 ; i<= k ; i++ ){
        fact = fact*i;
    } 
    cout<< fact;
    return fact;
    
}