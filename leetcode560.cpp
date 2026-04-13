#include<iostream>
#include<vector>
using namespace std;



// ======================BRUTFORCE APPROACH==========================================
// Time Complexity: O(n^3)
// int main(){
//     vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
//     int n = arr.size();
//     int key = 3;

//     int count = 0;
//     for(int i = 0; i<n; i++){
//         for(int j = i; j<n; j++){
//             int sum = 0;
//             for(int k = i; k<=j; k++){
//                 sum = sum+arr[k];
//             }
//             if(sum == key) count++; 
//         }
//     }
//     cout<<count;
//     return 0;
// }

// Time Complexity: O(n^2)
// int main(){
//     vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
//     int n = arr.size();
//     int key = 3;

//     int count = 0;
//     for(int i = 0; i<n; i++){
//         int sum = 0;
//         for(int j = i; j<n; j++){
//             sum  += arr[j];  
//             if(sum == key) count++; 
//         } 
//     }
//     cout<<count;
//     return 0;
// }



// =====================OPTIMISED APPROACH==========================================

int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int n = arr.size();
    int key = 3;

    int count = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum  += arr[j];  
            if(sum == key) count++; 
        } 
    }
    cout<<count;
    return 0;
}