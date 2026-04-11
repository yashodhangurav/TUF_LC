#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


// // better solution

// int longestConsecutive(vector<int> nums){
//     sort(nums.begin(), nums.end());                 //sorting the array

//     int n = nums.size();

//     int longest = 1;
//     int count = 0;
//     int lastSmall = INT_MIN;

//     for(int i = 0; i<n; i++){
//         if(nums[i]-1 == lastSmall){                //if the current number is one more than the last small number (if it is part of the sequence), then we can increase the count
//             count++;
//             lastSmall = nums[i];
//         }
//         else if(nums[i] != lastSmall){
//             lastSmall = nums[i];
//             count = 1;
//         }
//         longest = max(longest, count);                 //update the longest length
//     }
//     return longest;
// };

// int main(){

//     vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
//     cout<<longestConsecutive(nums);

//     return 0;
// }






// OPTIMAL solution

int longestConsecutive(vector<int> nums){
    sort(nums.begin(), nums.end());                 //sorting the array

    int n = nums.size();
    if(n == 0) return 0;

    unordered_set<int> s;
    for(int i = 0; i < n; i++){
        s.insert(nums[i]);
    }

    int longest = 0;

    for(auto it : s){
        // check if it's the start of a sequence
        if(s.find(it - 1) == s.end()){
            int count = 1;
            int currNum = it;

            // FIXED LOOP
            while(s.find(currNum + 1) != s.end()){
                currNum++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
};

int main(){

    vector<int> nums = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    cout<<longestConsecutive(nums);

    return 0;
}