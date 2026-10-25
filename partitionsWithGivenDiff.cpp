int mod = (int)(1e9 + 7);               //since the answers may be too large

class Solution {
  public:
    // int f(int ind, vector<int> &arr, int target, vector<vector<int>> &dp){
    //     if(ind == 0){
    //         if(arr[0] == 0 && target == 0) return 2;
    //         if(target == 0 || target == arr[0]) return 1;
    //         return 0;
    //     }
        
    //     if(dp[ind][target] != -1) return dp[ind][target];
        
    //     int notTake = f(ind-1,arr,target,dp);
    //     int take = 0;
    //     if(arr[ind]<=target){
    //         take = f(ind-1,arr,target-arr[ind],dp);
    //     }
    //     return dp[ind][target] = (take + notTake) %mod;
    // }
    
    // int findWays(vector<int> &arr, int target){
    //     int n = arr.size();
    //     vector<vector<int>> dp(n,vector<int>(target+1, -1));
        
    //     return f(n-1,arr,target,dp);
    // }
    
    // int countPartitions(vector<int>& arr, int diff) {
    //     // Code here
        
    //     int totalSum = 0;
    //     for(auto &it : arr) totalSum += it;
    //     if(totalSum-diff < 0 || (totalSum-diff) % 2 != 0 ) return 0;
        
    //     return findWays(arr, (totalSum-diff)/2);                            //div happens before sub, please give appropriate brackets everywhere
    // }
    
    
    
    //---------------------------------------Tabulation--------------------------------
   
    
    // int findWays(vector<int> &arr, int target){
    //     int n = arr.size();
    //     vector<vector<int>> dp(n,vector<int>(target+1, 0));
        
    //     if(arr[0] == 0) dp[0][0] = 2;
    //     else dp[0][0] = 1;
    //     if(arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
        
    //     for(int ind = 1; ind <n; ind++){
    //         for(int T = 0; T<=target; T++){
    //             int notTake = dp[ind-1][T];
    //             int take = 0;
    //             if(arr[ind] <= T) take = dp[ind-1][T-arr[ind]];
    //             dp[ind][T] = (take + notTake) % mod;
    //         }
    //     }
    //     return dp[n-1][target];
    // }
    
    // int countPartitions(vector<int>& arr, int diff) {
    //     // Code here
        
    //     int totalSum = 0;
    //     for(auto &it : arr) totalSum += it;
    //     if(totalSum-diff < 0 || (totalSum-diff) % 2 != 0 ) return 0;
        
    //     return findWays(arr, (totalSum-diff)/2);                            //div happens before sub, please give appropriate brackets everywhere
    // }
    
    
    //--------------------------------space optimization---------------------------
    int findWays(vector<int> &arr, int target){
        int n = arr.size();
        vector<int> prev(target+1, 0);
        vector<int> cur(target+1, 0);
        
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;
        
        for(int ind = 1; ind <n; ind++){
            for(int T = 0; T<=target; T++){
                int notTake = prev[T];
                int take = 0;
                if(arr[ind] <= T) take = prev[T-arr[ind]];
               cur[T] = (take + notTake) % mod;
            }
            prev = cur;
        }
        return prev[target];
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        
        int totalSum = 0;
        for(auto &it : arr) totalSum += it;
        if(totalSum-diff < 0 || (totalSum-diff) % 2 != 0 ) return 0;
        
        return findWays(arr, (totalSum-diff)/2);                            //div happens before sub, please give appropriate brackets everywhere
    }
};