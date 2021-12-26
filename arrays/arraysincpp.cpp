
#include<iostream>
#include<climits>
using namespace std;


int n;
int maxno = INT_MIN;
int minno = INT_MAX;
int key ,key2,h;
int temp,counter;



// ***************BINERY _ SEARCHING _ function ****************************//

int binarysearch(int userdefinedarray[], int n , int h){
            int s=0;
            int e=n;

            while(s<=e){

                int mid = (s+e)/2;
                if (userdefinedarray[mid]==h ){

                    cout<<h<<" is at index : "<<mid<<endl;
                    return 1;
                
                }
                else if(userdefinedarray[mid]>h){
                    e= mid-1;
                  
                }
                else {
                    s= mid+1;
                 
                }
            }return -1;
        };

int main(){
    
    

// ************** CREATING AN ARRAY ************************************// 

    //this is defined array 

    int numbers[11] = {11,13,12,14,15,16,17,18,19,20,12};
                 cout<<"element at index 5 is : "<<numbers[5]<<endl; //we can access element by using index

        cout<<"numbers array : ";
        for (int i=0;i<11;i++){
            cout<<numbers[i]<<" ,";
        }
        // for memory concept of array 
        cout<<endl<<"memory address of the elements are : "<<endl;
            cout<<&numbers[0]<<endl;
            cout<<&numbers[1]<<endl;
            cout<<&numbers[2]<<endl;
            cout<<&numbers[3]<<endl;
            cout<<&numbers[4]<<endl;
            cout<<&numbers[5]<<endl;
            cout<<&numbers[6]<<endl;
            cout<<&numbers[7]<<endl;
            cout<<&numbers[8]<<endl;
            cout<<&numbers[9]<<endl;
            cout<<&numbers[10]<<endl;
        cout<<"we know the int data type in cpp is of 4 bits so memory address are differ by 4 as you can see in output :  "<<endl;
        


// ***************LINEAR _ SEARCHING ****************************

        // this is linear searching in array by traversing each element irrespective of it found or not each element is cheaked compulsury.
        // if we want to know only first found element info then add break statement in a function while loop.
        

            cout<<endl<<"enter the element to linear search in numbers : ";
            cin >> key ;
            for (int i=0;i<11; i+=1){
            temp =numbers[i];
            if (temp == key){
                cout<<key<<"  is at index : "<<i<<endl;
               
            //  break ;   
             }
            }
    

// ****************** CREATING AN USER DEFINED ARRAY **************************

    // this is user defined array 

    int userdefinedarray[n];
        cout<<endl<<"enter value for userdefinedarray size n -: ";
        cin>>n;
        cout<<endl<<"enter userdefinedarray elements -: ";
        for (int i=0;i<n;i++){
            cin>>userdefinedarray[i];
        }

        cout<<endl<<"userdefinedarray is created as : ";

        for (int i=0;i<n;i++){
            cout<<userdefinedarray[i]<<" ,";
        }

        for (int i=0;i<n;i++){
            maxno = max(maxno,userdefinedarray[i]);
            minno = min(minno,userdefinedarray[i]);
        }
        cout <<endl<<"max no. in userdefinedarray is : "<< maxno << " and min no. is :  "<< minno <<endl;



// ****************************SEARCHING IN AN ARRAY ****************************

    // ***************LINEAR _ SEARCHING ****************************

        // this is linear searching in array by traversing each element irrespective of it found or not each element is cheaked compulsury.
        // if we want to know only first found element info then add break statement in a function while loop.
        

            cout<<endl<<"enter the element to linearly search in userdefinedarray : ";
            cin >> key ;
            for (int i=0;i<11; i+=1){
                temp =userdefinedarray[i];
                if (temp == key){
                    cout<<key<<"  is at index : "<<i<<endl;
                
                //  break ;   
                }
            }
   
    //***************BINERY _ SEARCHING ****************************

       // calling binary search funcion created above 

        cout<<"enter the element to binary search in userdefinedarray key -: "<<endl;
        cin>>h;
        cout<< binarysearch(userdefinedarray,n,h);


// ****************************SORTING IN AN ARRAY ****************************

    //***************SELECTION _ SORTING****************************
       
        // in this method elements are compare with one another and array get sorted.
            for(int i =0 ; i<n-1;i++){
                for (int j=i+1; j<n;j++){
                    if(userdefinedarray[j]<userdefinedarray[i]){
                        int temp = userdefinedarray[j];
                        userdefinedarray[j]=userdefinedarray[i];
                        userdefinedarray[i]=temp;
                    }
                }
            }
            cout <<endl<<endl<< "this is sorted user defined array by selection sort : ";
            for (int i=0 ;i<n;i++){
                cout<<userdefinedarray[i]<<" ,";
            }
    //*************** BUBBLE _ SORTING****************************
       
        // in this method adjacent elements are compare with one another and array get sorted.

        // ********** CREATING AN ARRAY ********
        int in;//in is index as we had used n var above so
            cout << endl<<"enter the size of arry to define an arry for testing bubble sort : ";
            cin>>in;
        int arr[in];
            cout << "enter elements for an array for testing bubble sort : "<<endl;
            for (int i=0 ;i<in;i++){
                cin>>arr[i];
            }
             cout << "the new user array has been created as for testing bubble sort : "<<endl;
            for (int i=0 ;i<in;i++){
                cout<<arr[i]<<" ,";
            }
            counter = 1;
        while(counter<in){
            for (int i =0;i<in-counter;i++){
                if(arr[i]>arr[i+1]){
                    temp = arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
            counter++;
        }
            cout <<endl<< "the new user array is sorted by bubble sort as : ";
            for (int i=0 ;i<in;i++){
                cout<<arr[i]<<" ,";
            }


    //*************** INSERTION _ SORTING****************************

        int ni;
            cout << endl << "enter the size of arry to define an ary to test insertion sort : ";
            cin>>ni;

        int ary[ni];//here ni variable is used for index

            cout << "enter elements for an array to test insertion sort : ";
            for (int i=0 ;i<ni;i++){
                cin>>ary[i];
            }

            // main algo of insertion sort
            for (int i=1;i<ni;i++){
            int current = ary[i];
            int j=i-1;
            while (ary[j]>current  && j>=0){
                ary[j+1]=ary[j];
                j--;
            }
            ary[j+1]=current;
        }

            cout << "this is sorted array by insertion sort : ";
            for (int i=0 ;i<ni;i++){
                cout<<ary[i]<<" ,";
            }



    return 0 ;
}
//ACESP's