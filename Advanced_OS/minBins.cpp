//program to understand the best-fit algorithm
#include<bits/stdc++.h>
using namespace std;

// utitlity function to find the minimum number of bins
// using the best-fit algorithm
int minimumBins(vector<double>&arr, int C){
    // size of the given arr[]
    int n = arr.size();

    // initializing the multiset to accomdate the free space
    multiset<double>mp;

    // declaring the count variable, to keep the check of number of bins requrired
    int count = 0;
    for(int i=0;i<n;i++){

        // checking if the avaiable space is
        // equal to the current element
        auto it = mp.find(arr[i]);

        // if empty space avaiable in the multiset
        // is itself equal to the current element
        if(it!=mp.end()){
            mp.erase(it);
        } else{
            // checking if the avaiable space in the
            // multiset is greater than current element or not
            auto it1 = mp.upper_bound(arr[i]);
            //if present
            if(it1!=mp.end()){
                // insert the next avaiable space after inserting the current element
                mp.insert(*it1 - arr[i]);
                // remove the space that is used
                mp.erase(it1);
            }else{
                // if there is no avaiable space, create the new bin
                // and hence increase the count
                count++;
                // and insert the remaining space into the multiset,
                // after creating the new bin
                mp.insert(C - arr[i]);
            }
        }
    }
    return count;
}
int main(){
    int numBags;
    cin >> numBags;

    vector<double> bagWeights(numBags);
    for (int i = 0; i < numBags; ++i) {
        cin >> bagWeights[i];
    }
    int C = 3;
    cout << minimumBins(bagWeights, C) << endl;
}