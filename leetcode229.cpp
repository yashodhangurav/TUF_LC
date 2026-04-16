#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

// vector<int> majorityElement(vector<int> v){
//     int n = v.size();
//     vector<int> ls;
//     int mini = int(n/2)+1;
//     map<int,int> mpp;

//     for(int i =0; i<n; i++){
//         mpp[v[i]]++;
//         if(mpp[v[i]] == mini){
//             ls.push_back(v[i]);
//         }
//         if(v.size() == 2) break;
//     }

//     sort(ls.begin(), ls.end());

//     return ls;
// }


vector<int> majorityElement(vector<int> v){
    int count1 = 0, count2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    for(int i = 0; i<v.size(); i++){
        if(count1 == 0 && el2 != v[i]){
            count1 = 1;
            el1 = v[i];
        }
        else if(count2 == 0 && el1 != v[i]){
            count2 =1;
            el2 = v[i];
        }
        else if(v[i] == el1) count1++;
        else if(v[i] == el2) count2++;
        else{
            count1--;
            count2--;
        }
    }

    vector<int> ls;
    count1 = 0;
    count2 = 0;
    for(int i = 0; i<v.size(); i++){
        if(el1 == v[i]) count1++;
        else if(el2 == v[i]) count2++;
    }
    int mini = int(v.size()/3)+1;
    if(count1>= mini) ls.push_back(el1);
    if(count2>= mini) ls.push_back(el2);

    sort(ls.begin(), ls.end());

    return ls;
}


// =========================================== OPTIMAL SOLUTION ====================================

int main(){

    vector<int> arr = {1,1,1,1,3,2,2,2};
    majorityElement(arr);

    
    return 0;
}