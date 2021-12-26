#include <iostream>
using namespace std;


int main(){
    int n,m;
    // cout<< "enter value for n : ";
    // cin>>n;
    //  cout<< "enter value for m : ";
    // cin>>m;
    int arr[1][50];
    // cout<<"enter the elements of an array : ";
   
    for(int i=0;i<1;i++){
        for(int j=0;j<50;j++){
            arr[i][j] = j;
        }
    }
    cout << "multidiamentional array has been created as : "<<endl;
    for(int i=0;i<1;i++){
        cout <<endl;
        for(int j=0;j<50;j++){
            cout <<arr[i][j] <<" ,";
        }
    }
    if(arr[0][49]==49){
        cout << "true"<<endl;
        //PRO TIP : we can defined size of an array in natural numbers but access them using index. 
    }
    

}