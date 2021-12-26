#include<iostream>
#include<climits>
#

using namespace std;

float p1x,p2x,p3x,p4x,p1y,p2y,p3y,p4y;

int main () {
    int reqpt=cin>>reqpt;
    float reqpt_const1 = reqpt/10;
  for (int i = 0; i < reqpt; i++) {


    float point1x = pow((1 - reqpt_const1), 3) * (p1x) + 3 * (pow(1 - reqpt_const1, 2) * reqpt_const1 * p2x + 3 * (1 - reqpt_const1) * (pow(reqpt_const1, 2)) * p3x + (pow(reqpt_const1, 3)) * p4x );
    float point1y = pow(1 - reqpt_const1, 3) * (p1y) + 3 * (pow(1 - reqpt_const1, 2) * reqpt_const1 * p2y + 3 * (1 - reqpt_const1) * (pow(reqpt_const1, 2)) * p3y + (pow(reqpt_const1, 3)) * p4y );

cout<<"   "<< point1x;
    reqpt_const1 = reqpt_const1+1/reqpt;
    reqpt_const1  = reqpt_const1+1/reqpt;
    

  }
}
