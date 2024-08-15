#include <iostream.h>
using namespace std;
int main(){
  int flag =0;
  string led="";
 if(flag==0) led="red";
 else if(flag==1) led = "green";
 else if (flag==2) led= "white";
if(digitalread(4)){
  counter++;
  flag=counter%3;
}
}