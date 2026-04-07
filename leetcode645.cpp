// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> findErrorNums( vector<int> nums ){
//     int n = nums.size();
//     int repeating,mising;
//         for(int val = 1; val<=n; val++){
//             int count = 0;
//             for(int i = 0; i<n; i++){
//                 if(nums[i] == val) count++;
//             }
//             if(count==0) mising = val;
//             else if (count > 1) repeating = val;
            
//         }

//         return {repeating, mising};                 //this syntax is used to return a vector with elements (without creating vector again)
// };

// int main(){
//     vector<int> nums = {1,2,4,4,5};
    
//     vector<int> ans = findErrorNums(nums);

//     cout<<"repeating : "<<ans[0]<<endl;
//     cout<<"mising : "<<ans[1]<<endl;
    
    
//     return 0;
// }



// --------------------------------------------Using best Time complexity method-------------
// frequency array concept

#include<iostream>
#include<vector>
using namespace std;

vector<int> findErrorNums( vector<int> nums ){

    int n = nums.size();

    vector<int> freq(n+1, 0);           //creating frequency array of size n+1 and giving default value as 0 for all ( we are keeping size one extra coz in nums array values range is 1-7, so we need 7th index also in our freq array to calc freq of 7)
    
    // for(int i = 0; i<n; i++){
    //     int val = nums[i];          //also we can write freq[nums[i]]++ in one line
    //     freq[val]++;
    // }

    // or

    for(int val : nums){            //for each loop (this loop take out the values present in the nums array)
        freq[val]++;
    }

    // now running the loop on frequency array to know repeating and missing values on 

    int missing,repeating;

    for(int i = 1; i<=n; i++){                  //staring from 1st index becoz nums range is 1-n, n+1 so we can directly involve n as well
        if(freq[i] == 0) missing = i;
        else if(freq[i]>1) repeating = i;          //becouse the values of nums becomes the indices of freq array so we return i itself
    }
    return {repeating, missing};
}

int main(){
    vector<int> nums = {1,2,4,4,5,6,7};
    
    vector<int> ans = findErrorNums(nums);

    cout<<"repeating : "<<ans[0]<<endl;
    cout<<"mising : "<<ans[1]<<endl;
    
    
    return 0;
}