#include<iostream>
#include<vector>
using namespace std;

// ================================== BRUTE FORCE APPROACH ===================================
// time complexity: O((n+m)log(n+m)), space complexity: O(n+m)

void merge(long long* arr1, long long* arr2, int n, int m){
    int left = 0, right = 0, idx = 0;
    vector<long long> arr3(n+m);

    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[idx] = arr1[left];
            left++;
            idx++;
        }else{
            arr3[idx] = arr2[right];
            right++;
            idx++;
        }
    }

    while(left < n){
        arr3[idx++] = arr1[left++]; 
    }
    while(right < m){
        arr3[idx++] = arr2[right++];
    }

    for(int i = 0; i<n+m; i++){
        if(i<n) arr1[i] = arr3[i];
        else arr2[i-n] = arr3[i];
    }
}

int main(){

    long long arr1[] = {1,3,5,7};
    long long arr2[] = {0,2,4,6,8,9};

    int n = sizeof(arr1)/sizeof(arr1[0]);
    int m = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, arr2, n, m);

    return 0;
}