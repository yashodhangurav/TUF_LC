// class Solution {
//   public:
//     int f(int ind,vector<int> &val, vector<int> &wt, int W, vector<vector<int>>&dp){
//         if(ind == 0){
//             if(wt[ind] <=W){
//                 return val[ind];
//             }else return 0;
//         }
//         if(dp[ind][W] != -1) return dp[ind][W];
        
//         int notTake = 0 + f(ind-1,val,wt,W,dp);
//         int take = INT_MIN;
//         if(wt[ind] <=W){
//             take = val[ind] + f(ind-1,val,wt,W-wt[ind],dp);
//         }
//         return dp[ind][W] = max(notTake,take);
//     }
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         // code here
//         int n = val.size();
//         vector<vector<int>> dp(n,vector<int>(W+1,-1));
        
//         return f(n-1,val,wt,W,dp);
//     }
// };
// T.C. = O(n*w)
// S.C. = O(n*w)


//------------------------------------Tabulation--------------------------------

// class Solution {
//   public:
    
//     int knapsack(int W, vector<int> &val, vector<int> &wt) {
//         // code here
//         int n = val.size();
//         vector<vector<int>> dp(n,vector<int>(W+1,0));
        
//       for(int w = wt[0]; w<=W; w++) dp[0][w] = val[0];
        
//         for(int ind = 1; ind<n; ind++){
//             for(int w = 0; w<=W; w++){
                
//                  int notTake = 0 + dp[ind-1][w];
//                  int take = INT_MIN;
//                  if(wt[ind] <=w){
//                     take = val[ind] + dp[ind-1][w-wt[ind]];
//                 }
//             dp[ind][w] = max(notTake,take);
                
//             }
//         }
        
//         return dp[n-1][W];
//     }
// };





//------------------------------space optimization--------------------------------


class Solution {
    public:
      
      int knapsack(int W, vector<int> &val, vector<int> &wt) {
          // code here
          int n = val.size();
          vector<int>prev(W+1,0);
          vector<int>cur(W+1,0);
          
         for(int w = wt[0]; w<=W; w++) prev[w] = val[0];
          
          for(int ind = 1; ind<n; ind++){
              for(int w = 0; w<=W; w++){
                  
                   int notTake = 0 + prev[w];
                   int take = INT_MIN;
                   if(wt[ind] <=w){
                      take = val[ind] + prev[w-wt[ind]];
                  }
            cur[w] = max(notTake,take);
                  
              }
              prev = cur;
          }
          
          return prev[W];
      }
  };