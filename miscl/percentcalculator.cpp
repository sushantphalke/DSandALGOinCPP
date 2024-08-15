#include<iostream>
using namespace std;

   int i=0;
  double t=0.16;

int main(){
 
    for (i=1;i<11;i++){
        
          double  x= t*0.3;
         double l=t+x;
        cout<<"value:"<<l<<endl;
        t=l;
    }
}