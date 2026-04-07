#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& nums) {
    for(int i = nums.size()-1; i>=0; i--){
        if(nums[i] == 9){
            nums[i] = 0;
        }
        else {
            nums[i]++; 
            break;
        } 
    }

    // if the array containing all 9's then we need to increase array size by one and should add 1 in front
    if(nums[0]==0){                            //if the first element itself is zero that means all elements was 9
        vector<int> res(nums.size()+1, 0);
        res[0] = 1;                         //initialized first element as 1
        return res;
    }

    return nums;
}

int main(){

    vector<int> nums = {1,2,4,4,5,6,7};
    vector<int> ans = plusOne(nums);

    

    return 0;
}