#include<iostream>
#include<vector>
using namespace std;


// ========================================BRUTE FORCE ========================================
// time complexity: O(r) and space complexity: O(1)

// int nCr(int n, int r){
//     int res = 1;

//     for(int i = 0; i<r; i++){
//         res = res * (n-i);
//         res = res/(i+1);
//     }
//     return res;
// }



// // printing the Nth row
// // time complexity: O(n*r) and space complexity: O(1)
// void printNthRow(int n){
//     for(int i = 1; i<=n; i++){
//         cout<<nCr(n-1, i-1)<<" ";
//     }
// }

// int main(){

//     // by using the nCr formula we can find the value of the pascal triangle

//     int n = 5, r = 3;
//     int res = 1;

//     cout<<nCr(n-1,r-1);

//     cout<<endl;

//     printNthRow(n);

//     return 0;
// }



// ========================================OPTIMIZED APPROACH========================================


vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);                                               // for r = 0 the value will be 1

    for(int col = 1; col < row; col++){
        ans = ans * (row-col);
        ans = ans/(col);

        ansRow.push_back(ans); 
    }
    return ansRow;
}

vector<vector<int>> generatePascalTriangle(int n){
    vector<vector<int>> pascalTriangle;

    for(int i = 1; i<=n; i++){
        pascalTriangle.push_back(generateRow(i));
    }
    return pascalTriangle;
}


int main(){

    // by using the nCr formula we can find the value of the pascal triangle

    int n = 5, r = 3;
    int res = 1;

//    nCr(n,r);


    generateRow(n);

    cout<<endl;

    // printNthRow(n);

    // printPascalTriangle(n);

    return 0;
}




