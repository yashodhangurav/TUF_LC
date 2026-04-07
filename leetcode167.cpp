//------- pair sum
// two pointer approach

#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int> arr, int n){
    int st = 0, end = arr.size()-1;         //we are taking two varibale at start and end index number
    int currSum = 0;
    vector<int> ans;            //this is created another vector to add the index number which are giving the sum of target    

    while(st<end){
        currSum = arr[st] + arr[end];
        if(currSum == n){
            ans.push_back(st);
            ans.push_back(end);
            return ans;
        }else if(currSum > n){
            end--;
        }else{
            st++;
        }
    }
    return ans;
};


int main(){
    vector<int> vec = {2,7,11,15};
    int target = 9;
    vector<int> ans = pairSum(vec, target);
    cout<<ans[0]<<", "<<ans[1]<<endl;
    return 0;
}



// class Solution {
//     public:
//         vector<int> twoSum(vector<int>& numbers, int target) {
//             int left = 0;
//             int right = numbers.size() - 1;
    
//             while(left < right) {
//                 int sum = numbers[left] + numbers[right];
    
//                 if(sum == target) {
//                     return {left + 1, right + 1};   // 1-indexed
//                 }
//                 else if(sum < target) {
//                     left++;
//                 }
//                 else {
//                     right--;
//                 }
//             }
    
//             return {}; // not needed because solution always exists
//         }
//     };
    