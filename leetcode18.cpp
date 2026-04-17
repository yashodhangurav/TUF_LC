#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


// =====================================BRUTE FORCE=================================
// time complexity: O(n^4) and space complexity: O(n^4) in worst case when all the quadruplets are unique
// vector<vector<int>> fourSum(vector<int> &nums, int target){
//     int n = nums.size();
//     set<vector<int>> s;

//     for(int i = 0; i<n; i++){
//         for(int j = i+1; j<n; j++){
//             for(int k = j+1; k<n; k++){
//                 for(int l = k+1; l<n; l++){
//                     long long sum = nums[i]+nums[j];
//                     sum += nums[k];
//                     sum += nums[l];
//                     if(sum == target){
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                         sort(temp.begin(), temp.end());
//                         s.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(s.begin(), s.end());
//     return ans;
// }


// ===============================BETTER SOL===================================
// time complexity: O(n^3) and space complexity: O(n^3) in worst case when all the quadruplets are unique

// vector<vector<int>> fourSum(vector<int> &nums, int target){
//     int n = nums.size();
//     set<vector<int>> s;

//     for(int i = 0; i<n; i++){
//         for(int j = i+1; j<n; j++){
//             set<long long> hashset;
//             for(int k = j+1; k<n; k++){
//                 long long sum = nums[i]+nums[j];
//                 sum += nums[k];
//                 long long fourth = target - (sum);
//                 if(hashset.find(fourth) != hashset.end()){
//                     vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
//                     sort(temp.begin(), temp.end());
//                     s.insert(temp);
//                 }
//                 hashset.insert(nums[k]);
//             }
//         }
//     }
//     vector<vector<int>> ans(s.begin(), s.end());
//     return ans;
// }



// ===================================OPTIMIZE SOL=============================================
// time complexity: O(n^3) and space complexity: O(number of quards) we are not used any space to solve the problm but we are using space to store the answer in the vector of vector

vector<vector<int>> fourSum(vector<int> &nums, int target){
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue; // skip duplicates for the first number
        for(int j = i+1; j<n; j++){
            if(j > i+1 && nums[j] == nums[j-1]) continue; // skip duplicates for the second number

            int k = j+1;
            int l = n-1;

            while(k<l){
                long long sum = nums[i]+nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;l--;

                    while(k<l && nums[k] == nums[k-1])k++; // skip duplicates for the third number
                    while(k<l && nums[l] == nums[l+1])l--;
                }else if(sum<target) k++;
                else l--;
            }
        }
    }
    return ans;
}


int main(){

        vector<int> nums = {1, 0, -1, 0, -2, 2};
        int target = 0;
        vector<vector<int>> ans = fourSum(nums, target);
        for(int i = 0; i<ans.size(); i++){
            for(int j = 0; j<ans[i].size(); j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    return 0;
}