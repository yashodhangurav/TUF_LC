// asked in amazon, microsoft, google, facebook, adobe, apple, netflix, uber, yandex

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;


// ===================================BRUTEFORCE APPROACH===================================
// time complexity: O(n^3)  space complexity: O(n) for set, O(1) for answer vector,  

// int main(){
//     vector<int> nums = {-1,0,1,2,-1,-4};
//     int n = nums.size();

//     set<vector<int>> s;                         //set to store unique triplets


//     for(int i = 0; i<n; i++){
//         for(int j = i+1; j<n; j++){
//             for(int k = j+1; k<n; k++){

//                 if(nums[i]+nums[j]+nums[k] == 0){
//                         vector<int> temp = {nums[i], nums[j], nums[k]};
//                         sort(temp.begin(), temp.end());
//                         s.insert(temp);
//                      }
//                  }
                    
                    
//                 }
//             }
//             vector<vector<int>> ans(s.begin(), s.end());          //convert set to vector

//             // printing the answer
//             for(auto triplet : ans){
//                 for(auto num : triplet){
//                     cout<<num<<" ";
//                 }
//                 cout<<endl;
//             }

//     return 0;
// }



// ===================================BETTER APPROACH===================================
// time complexity: O(n^2)  space complexity: O(n) for storing the answer in set

// int main(){
//     vector<int> nums = {-1,0,1,2,-1,-4};
//     int n = nums.size();

//     set<vector<int>> s;                         //set to store unique triplets


//     for(int i = 0; i<n; i++){
//         set<int> hashSet;                      //hashset to store the elements of the array
//         for(int j = i+1; j<n; j++){
            
//                 int third = -(nums[i]+nums[j]);             //the third element that we need to find
//                 if(hashSet.find(third) != hashSet.end()){
//                     vector<int> temp = {nums[i], nums[j], third};
//                     sort(temp.begin(), temp.end());
//                     s.insert(temp);
//                 }
//                 hashSet.insert(nums[j]);                      //insert the second element in the hashset
//             }

//         }

//             vector<vector<int>> ans(s.begin(), s.end());          //convert set to vector

//             // printing the answer
//             for(auto triplet : ans){
//                 for(auto num : triplet){
//                     cout<<num<<" ";
//                 }
//                 cout<<endl;
//             }

//     return 0;
// }


// =================================================== OPTIMAL SOLUTION =====================================


vector<vector<int>> triplet(vector<int> nums, int n){
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i<n; i++){
        if(i>0 && nums[i] == nums[i-1]) continue; //skip duplicates
        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k && nums[j] == nums[j-1]) j++; //skip duplicates
                while(j<k && nums[k] == nums[k+1]) k--; //skip duplicates
            }        
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    int n = nums.size();

    triplet(nums, n);


    



    return 0;
}