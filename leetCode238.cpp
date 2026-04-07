// product of array except self

#include<iostream>
using namespace std;

int productArr(int arr[], int n){
    int mul = 1;
    int count = 0;

    for(int i = 0; i<n; i++){
        mul = mul* arr[i];
        if(arr[i] == 0){
            count++;
        }

        if(arr[i] != 0 ){
            if(count == 0){
                return mul;
            }else{
                return 0;
            }
        }else{
            return mul;
        }
    }
    
    return mul;
}

int main(){
    int arr[4] ={1,2,3,4};
    int n = sizeof(arr)/sizeof(int);

    cout<<productArr(arr, n);

    return 0;
}