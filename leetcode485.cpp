#include<iostream>
using namespace std;

int main(){     //O(n) time complexity and O(1) space complexity

    int arr[] = {1,1,0,1,1,1,0,1,1,0};
    int n = sizeof(arr)/sizeof(int);

    int count = 0, maxCount = 0;

    for(int i = 0; i<n; i++){
        if(arr[i] == 1){
            count++;
            maxCount = max(maxCount, count);
        }else{
            count = 0;
        }
    }

    cout<<maxCount;
    return 0;
}