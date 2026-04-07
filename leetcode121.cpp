#include<iostream>
using namespace std;

// -------------------------------BRUTE FORCE----------------------------
// int main(){
//     int arr[] = {7,1,5,3,6,4};
//     int n = sizeof(arr)/sizeof(int);

//     int max_profit = INT_MIN;
//     int profit = 0;
    
//     for(int i = 0; i<n; i++){
//         int min = arr[0];
//         for(int j = i+1; j<n; j++){
//             if(min > arr[j]){
//                 min = arr[j];
//             }else{
//                 profit = arr[j] - min;
//                 max_profit = max(max_profit, profit);
//             }
//         }
//     }

//     cout<<max_profit;
//     return 0;
// }




// -------------------------------OPTIMIZED----------------------------
// using DP = which is remembering the past

int main(){                                     //O(n) time complexity and O(1) space complexity
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(int);

    int max_profit = 0;
    int mini = arr[0];

    for(int i = 1; i<n; i++){
        if(mini > arr[i]){
            mini = arr[i];
        }
        int cost = arr[i] - mini;
        max_profit = max(max_profit, cost);

        mini = min(mini, arr[i]);
    }
   
    cout<<max_profit;
    return 0;
}