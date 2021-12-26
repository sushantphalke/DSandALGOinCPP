#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<climits>
#include <stack>

int main(){
	
	int q=0;
	int w=0;
	int arraysize = 0;
	
	
	// cout<<"enter no of curves in one single path"<<endl;
	// cin >>noofcurves;
	



		// float arr2[noofcurves]={};
		// float arr1[100]={};

		float p1x=2 ;// cout<<"Enter x co-ordinate of start point"<<endl;cin>>p1x;
		float p1y=2 ;//cout<<"Enter y co-ordinate of start point"<<endl;cin>>p1y;
		float p2x=2 ;//cout<<"Enter x co-ordinate of 2nd point"  <<endl;cin>>p2x;
		float p2y =200;//cout<<"Enter y co-ordinate of 2nd point"  <<endl;cin>>p2y;
		float p3x =200;//cout<<"Enter x co-ordinate of 3rd point"  <<endl;cin>>p3x;
		float p3y =200;//cout<<"Enter y co-ordinate of 3rd point"  <<endl;cin>>p3y;
		float p4x=200; //cout<<"Enter x co-ordinate of final point"<<endl;cin>>p4x;
		float p4y =2;//cout<<"Enter y co-ordinate of final point"<<endl;cin>>p4y; 
		
		double setpoints[8][2]={{1,1},{1,200},{200,200},{200,1},{400,1},{400,200},{600,200}};
	

		
		

		// cout<<"how many point curve you required? "<<endl;
		// cin >>requiredpoints ;

		

		// int array1index = (requiredpoints*2)+t*2;

double arr1[30][2]={};
int t=0 ;
int curves =2;
for (int c=0; c< curves; c++){
	double requiredpoints = 10;
 	double gamma = 1/requiredpoints;

	for (int i = 0 ; i<requiredpoints; i++) {
	
		
		// cout << i;

		float point1x = pow((1 - gamma), 3) * (setpoints[q][0]) + 3 * pow((1 - gamma), 2) * gamma * (setpoints[q+1][0]) + 3 * (1 - gamma) * (pow(gamma, 2)) * setpoints[q+2][0] + (pow(gamma, 3)) * setpoints[q+3][0] ;
		float point1y = pow((1 - gamma), 3) * (setpoints[q][1]) + 3 * pow((1 - gamma), 2) * gamma * (setpoints[q+1][1]) + 3 * (1 - gamma) * (pow(gamma, 2)) * setpoints[q+2][1] + (pow(gamma, 3)) * setpoints[q+3][1] ;
			// cout << " gamma  "<< gamma <<"  ";
			//cout << "  point1x "<< point1x <<endl; 
			arr1[t][0] = point1x;
			//cout << "  point2y "<< point1y<<endl; 

			arr1[t][1] = point1y;

			gamma = gamma+ 1/requiredpoints;

			// cout << " const "<< gamma <<endl;
			
			t=t+1;
		}
		q=q+3;
		
	

}


// for (int i =; i<requiredpoints;i++)

//  arr2[i] = arr1[i];
 
	cout<<"curvepoints : "<<endl;
        for (int i=0; i<t; i++){
            cout<<"    {"<<arr1[i][0]<<","<<arr1[i][1]<<"} , "<<endl;
        }
}
