#include<iostream>
using namespace std;
int n;

int main(){
    
 // ************** CREATING AN USER DEFINED ARRAY ************************************
 int n;
            cout << "enter the size of arry to define an arry : ";
            cin>>n;
        int arr[n];
            cout << "enter elements for an array : ";
            for (int i=0 ;i<n;i++){
                cin>>arr[i];
            }
            cout << "the Array is Created as :[ ";
            for (int i=0 ;i<n;i++){
                cout<<arr[i];
                if (i<=n-2){
                    cout<<" ,";
                }
            }
            cout<<"]";
} 