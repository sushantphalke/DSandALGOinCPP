#include<omp.h>
#include<iostream>
using namespace std;
void par_bubble(int *arr,int n){
    #pragma omp parallel num_threads(4) shared(arr, n) private(i, j, temp, swapped)
    for(int i=0;i<n-1;i++){
        #pragma omp parallel
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    
}
int main(){
    int arr[5]={1,3,2,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"before:"<<arr;
    par_bubble(arr,n);
    cout<<"after:"<<arr;
    return 0;
}
