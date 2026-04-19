#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// =============================== BRUTE FORCE ===============================
// time complexity: O(nlogn) for sorting  + O(2n) = O(2n)
// space complexity: O(n) for storing the ans vector
// vector<vector<int>> mergeOver(vector<vector<int>> &arr){
//     sort(arr.begin(), arr.end());
//     int n = arr.size();
//     vector<vector<int>> ans;

//     for(int i = 0; i<n; i++){
//         int start = arr[i][0];
//         int end = arr[i][1]; 

//         if(!ans.empty() && ans.back()[1]>= end){
//             continue;
//         }

//         for(int j = i+1; j<n; j++){             //if secons ele of the first pair is greater than the first ele of the second pair then we can merge them
//             if(arr[j][0] <= end){
//                 end = max(end, arr[j][1]);
//             }else{
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
// }


// ==`============================ OPTIMIZED APPROACH ===============================

// time complexity: O(nlogn) for sorting  + O(n) = O(nlogn)
// space complexity: O(n) for storing the ans vector

vector<vector<int>> mergeOver(vector<vector<int>> &arr){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> ans;

    for(int i = 0; i<n; i++){
       if(ans.empty() || arr[i][0] > ans.back()[1]){
        ans.push_back(arr[i]);
       }
       else{
        ans.back()[1] = max(ans.back()[1], arr[i][1]);
       }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,1},{9,1},{8,1},{2,4},{15,8}};

    mergeOver(arr);

    return 0;
}