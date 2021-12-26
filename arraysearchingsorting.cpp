#include<iostream>
#include<climits>
using namespace std;



int n;
int maxno = INT_MIN;
int minno = INT_MAX;
int key ,key2 ,h;
int temp;




int main(){
    
 // ************** CREATING AN ARRAY ************************************ 

        int n;
            cout << "enter the size of arry to define an arry : ";
            cin>>n;
        int arr[n];
            cout << "enter elements for an array : ";
            for (int i=0 ;i<n;i++){
                cin>>arr[i];
            }




// ****************************SEARCHING IN AN ARRAY ****************************


    // ***************LINEAR _ SEARCHING ****************************

        // this is linear searching in array by traversing each element irrespective of it found or not each element is cheaked compulsury.
        // if we want to know only first found element info then add break statement in a function while loop.
        

            // cout<<endl<<"enter the element to linear search in array : ";
            // cin >> key ;
            // for (int i=0;i<11; i+=1){
            // int temp =arr[i];
            // if (temp == key){
            //     cout<<key<<"  is at index : "<<i<<endl;
               
            // //  break ;   
            //  }
            // }




//***************BINERY _ SEARCHING ****************************


            // cout<<"enter the value for binary search in userdefinedarray key -: "<<endl;
            // cin>>h;

            // int s=0;
            // int e=n;
            // while(s<=e){
            //     int mid = (s+e)/2;
            //     if (arr[mid]==h ){

            //         cout<<h<<" is at index : "<<mid<<endl;
            //         return 1;
                
            //     }
            //     else if(arr[mid]>h){
            //         e= mid-1;
                  
            //     }
            //     else {
            //         s= mid+1;
                 
            //     }
            // }
        




// ****************************SORTING IN AN ARRAY ****************************


    //***************SELECTION _ SORTING****************************
       
        // // in this method elements are compare with one another and array get sorted.
        //     for(int i =0 ; i<n-1;i++){
        //         for (int j=i+1; j<n;j++){
        //             if(arr[j]<arr[i]){
        //                 int temp = arr[j];
        //                 arr[j]=arr[i];
        //                 arr[i]=temp;
        //             }
        //         }
        //     }
        //     cout << "this is sorted array : ";
        //     for (int i=0 ;i<n;i++){
        //         cout<<arr[i]<<" ,";
        //     }
        
        int ni;
            cout << "enter the size of arry to define an ary to test insertion sort : ";
            cin>>ni;
        int ary[ni];//here ni variable is used for index
            cout << "enter elements for an array to test insertion sort : ";
            for (int i=0 ;i<ni;i++){
                cin>>ary[i];
            }
   
            for (int i=1;i<ni;i++){
            int current = ary[i];
            int j=i-1;
            while (ary[j+1]>current  && j>=0){
                ary[j+1]=ary[j];
                j--;
            }
            ary[j+1]=current;
        }
            cout << "this is sorted array : ";
            for (int i=0 ;i<n;i++){
                cout<<arr[i]<<" ,";
            }
    
    return 0;
    
}