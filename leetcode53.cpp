#include<iostream>
using namespace std;


// ----------------------------- ----------------------BRUTE FORCE Approach ----------------------------

// int main(){                                         //near about O(n^3), space = O(1)
//     int arr[] = {-2,-3,4,-1,-2,1,5,-3};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int max_sum = INT_MIN;

//     for(int  i = 0; i<n; i++){
//         for(int j = i; j<n; j++){
//             int sum = 0;
//             for(int k = i; k<=j; k++){
//                 sum += arr[k];
//                 max_sum = max(max_sum, sum);
//             }
//         }
//     }

//     cout<<max_sum<<endl;
//     return 0;
// }


// ----------- --------------------BETTER APPROACH-------------------------------

// int main(){                                         // O(n^2)
//     int arr[] = {-2,-3,4,-1,-2,1,5,-3};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     int max_sum = INT_MIN;

//     for(int  i = 0; i<n; i++){
//         int sum = 0;
//         for(int j = i; j<n; j++){
//             sum += arr[j];
//             max_sum = max(max_sum, sum);
//         }
//     }

//     cout<<max_sum<<endl;
//     return 0;
// }


// -------------------------------- OPTIMAL SOL (KANDANES Algorithm )---------------------------------------------- 

int main(){                                         // O(n) and space = O(1)
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_sum = INT_MIN;
    int sum = 0;
    for(int  i = 0; i<n; i++){
        sum += arr[i];
        max_sum = max(max_sum, sum);
        if(sum <0){
            sum = 0;
        }
    }
    cout<<max_sum<<endl;
    return 0;
}