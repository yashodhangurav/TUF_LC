/* steps to find the next permutation of a given array of numbers:
// BRUTE FORCE:- (but here TC is very high because of generating all the possible permutation and then searching for the given array and then returning the next one)
1. generate all the possible permutation
2. find or search by using linear search 
3. next permutation , if there is no next permutation then return the lowest order (sorted in ascending order)

// BETTER SOL:-
by using the STL function next_permutation() we can find the next permutation of the given array in O(n) time complexity and O(1) space complexity

// OPTIMAL SOL:-


*/ 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int> &arr){
    int n = arr.size();

    int idx = -1;

    for(int i = n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            idx = i;
            break;
        }
    }

    if(idx == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    for(int i = n-1; i>=idx; i--){
        if(arr[i]>arr[idx]){
            swap(arr[i], arr[idx]);
            break;
        }
    }

    reverse(arr.begin()+idx+1, arr.end());
};


void printArr(vector<int> &arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {2,1,5,4,3,0,0};

    nextPermutation(arr);

    printArr(arr);
    return 0;
}