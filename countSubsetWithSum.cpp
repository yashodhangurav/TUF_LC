class Solution {
    public:
      // int f(int ind, vector<int> &arr, int target,vector<vector<int>> &dp){
      //     if (ind == 0) {
      //         if (target == 0 && arr[0] == 0) return 2;
      //         if (target == 0 || arr[0] == target) return 1;
      //         return 0;
      //     }
          
      //     if(dp[ind][target] != -1) return dp[ind][target];
          
      //     int notPick = f(ind-1,arr,target,dp);
      //     int pick = 0;
      //     if(arr[ind]<=target){
      //         pick = f(ind-1,arr,target-arr[ind],dp);
      //     }
      //     return dp[ind][target] =  pick + notPick;
      // }
      
      
      //----------------------------------tabulation
      
      // int perfectSum(vector<int>& arr, int target) {
      //          int n = arr.size();
      //          vector<vector<int>> dp(n,vector<int>(target+1,0));
  
  
      //         if (arr[0] == 0) {
      //                  dp[0][0] = 2;
      //              } else {
      //                  dp[0][0] = 1;
      //                  if (arr[0] <= target) {
      //                      dp[0][arr[0]] = 1;
      //                  }
      //              }
  
  
      //          for(int ind = 1; ind<n; ind++){
      //              for(int t = 0; t<=target;t++){
  
      //                  int notPick = dp[ind-1][t];
      //                  int pick = 0;
      //                  if(arr[ind]<=t){
      //                      pick = dp[ind-1][t-arr[ind]];
      //                  }
      //                   dp[ind][t] = pick+notPick;
      //              }
  
      //          }
  
      //          return dp[n-1][target];
      //      }
      //  };
      
      
      
      
      
      
      //------------------------------------------------space optimized
      
      int perfectSum(vector<int>& arr, int target) {
          int n = arr.size();
          vector<int>prev (target+1,0);
          vector<int>cur (target+1,0);
        
      
         if (arr[0] == 0) {
                  prev[0] = 2;
              } else {
                 prev[0] = 1;
                  if (arr[0] <= target) {
                     prev[arr[0]] = 1;
                  }
              }
           
          
          for(int ind = 1; ind<n; ind++){
              for(int t = 0; t<=target;t++){
                  
                  int notPick = prev[t];
                  int pick = 0;
                  if(arr[ind]<=t){
                      pick = prev[t-arr[ind]];
                  }
                  cur[t] = pick+notPick;
              }
             prev = cur;
          }
          
          return prev[target];
      }
  };