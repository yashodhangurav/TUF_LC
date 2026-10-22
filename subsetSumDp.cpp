class Solution {
    public:
      // bool f(int ind,vector<int>&arr, int target, vector<vector<int>> &dp){
      //     if(target == 0) return true;
      //     if(ind == 0) return (arr[0] == target);
          
      //     if(dp[ind][target] != -1) return dp[ind][target];
          
      //     int notTake = f(ind-1,arr,target,dp);
      //     int take = false;
      //     if(arr[ind] <= target){
      //         take = f(ind-1,arr,target-arr[ind],dp);
      //     }
      //     return dp[ind][target] = take | notTake;
      // }
      
      // bool isSubsetSum(vector<int>& arr, int target) {
      //     // code here
      //     int n = arr.size();
      //     vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
          
      //     return f(n-1,arr,target,dp);
      // }
      
      
    //Tabulation
       bool isSubsetSum(vector<int>& arr, int target) {
          // code here
          int n = arr.size();
          vector<bool> prev(target+1,false);
          vector<bool> cur(target+1,false);
          
             prev[0] = true;
          
          if(arr[0] <=target) prev[arr[0]] = true;
          for (int ind = 1; ind < n; ind++) {
                  cur[0] = true;
          }
         
          
          for(int ind = 1; ind<n; ind++){
              for(int T = 1; T<=target; T++){
                  int notTake = prev[T];
                  int take = false;
              if(arr[ind] <= T){
                  take = prev[T-arr[ind]];
              }
              cur[T] = take | notTake;
              }
              prev = cur; 
          }
          
          return prev[target];
      }
  };



//   // Tabulation using 2D DP
// bool isSubsetSum(vector<int>& arr, int target) {
//     int n = arr.size();

//     vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

//     // Base case: target 0 is always possible
//     for (int i = 0; i < n; i++) {
//         dp[i][0] = true;
//     }

//     // Base case: first element
//     if (arr[0] <= target) {
//         dp[0][arr[0]] = true;
//     }

//     // Fill the DP table
//     for (int ind = 1; ind < n; ind++) {
//         for (int T = 1; T <= target; T++) {

//             bool notTake = dp[ind - 1][T];

//             bool take = false;
//             if (arr[ind] <= T) {
//                 take = dp[ind - 1][T - arr[ind]];
//             }

//             dp[ind][T] = take || notTake;
//         }
//     }

//     return dp[n - 1][target];
// }