#include<iostream>
#include<vector>
using namespace std;

int main(){ 
    int arr[] = {1,1,2,3,3,4,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int xxor = 0;
    for(int i = 0; i<n; i++){
        xxor = xxor ^ arr[i];
    }
    cout<<xxor<<endl;
    
    return 0;
}