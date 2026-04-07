#include<iostream>
#include<vector>
using namespace std;

// ----------------------------------BETTER SOL---------------------------------
// int main(){
//     vector<int> arr = {3,1,-2,-5,2,-4};
//     int n = arr.size();
//     vector<int> ans(n,0);

//     int pos = 0, neg = 1;

//     for(int i = 0; i < n; i++){
//         if(arr[i]<0){
//             ans[neg] = arr[i];
//             neg += 2;
//         }else{
//             ans[pos] = arr[i];
//             pos += 2;
//         }
//     }

//     for(int i = 0; i<n; i++){
//         cout<<ans[i]<<" ";
//     }

//     return 0;
// }


// ---------------------------------------- OPTIMAL SOL -------------------------------------
int main(){
    vector<int> arr = {-1,2,3,4,5,-6};
    int n = arr.size();
    vector<int> ans(n,0);

    vector<int> pos, neg;

    for(int i = 0; i<n; i++){
        if(arr[i]<0){
           neg.push_back(arr[i]); 
        }else{
            pos.push_back(arr[i]);
        }
    }

    if(neg.size() > pos.size()){
        for(int i =0; i<pos.size(); i++){
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];
        }

        int index = pos.size() * 2;
        for(int i = pos.size(); i<neg.size(); i++){
            ans[index] = neg[i];
            index++;
        }
    }
    else{
        for(int i = 0; i<neg.size(); i++){
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i  = neg.size(); i<pos.size(); i++){
            ans[index] = pos[i];
            index++;
        }
    }
    
    for(int i = 0; i<n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}