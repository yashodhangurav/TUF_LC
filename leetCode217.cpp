// contains Duplicate - TC - O(n*(n-1)/2)
// here we are did this without sorting thats why we need 2 loops , otherwise it can be possible with one loops if we used to sorting
// #include<iostream>
// using namespace std;

// int duplicate(int arr[], int n){
//     for(int i=0; i<n; i++){             //n
//         for(int j=i+1; j<n; j++){       //n-1
//             if(arr[i]==arr[j]){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// int main(){
//     int arr[5]={4,8,7,1,6};
//     int n = sizeof(arr)/sizeof(int);

//     cout<<duplicate(arr, n);
//     return 0;
// }

// this is exceed the time limit so we can go for the different method will learn in upcoming lectures