// running sum (important concept)

#include<iostream>
#include<vector>
using namespace std;

int runningSum(int nums[], int n){
    // optimized with less Time complexity - O(n)

    int n = nums.size();
        vector<int> res;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        cout<<sum<<", ";
        res.push_back(sum);
    }
    return 0;

    // or
// not optimized coz we used here nested loops 
    // for(int i=0; i<n; i++){
    //     int sum = 0;
    //     for(int j =0; j<=i; j++){
    //         sum += arr[j];
    //     }
    //     res.push_back(sum);
    // }
    // return 0;
    
    
}
int main(){
    int arr[5] = {5,7,9,4,1};
    int n = sizeof(arr)/sizeof(int);

    runningSum(arr,n);
    return 0;
}





