#include<iostream>
#include<vector>

using namespace std;



// ==================================BRUTE FORCE METHOD=========================
// void markRow(int mat[][4], int i){
//     int m = 4;
//     for(int j = 0; j<m; j++){
//         if(mat[i][j] != 0){
//             mat[i][j] = -1;
//         }
//     }
// }

// void markCol(int mat[][4], int j){
//     int n = 4;
//     for(int i = 0; i<n; i++){
//         if(mat[i][j] != 0){
//             mat[i][j] = -1;
//         }
//     }
// }

// int main(){

//     int mat [4][4] = {
//                     {1, 1, 1, 1}, 
//                     {1, 0, 0, 1}, 
//                     {1, 1, 0, 1},
//                     {1, 1, 1, 1}};
//     int m = 4, n = 4;
    
//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if(mat[i][j] == 0){
//                 markRow(mat, i);
//                 markCol(mat, j);
//             }
//         }
//     }

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if(mat[i][j] == -1){
//                 mat[i][j] = 0;
//             }
//         }
//     }

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//            cout<<mat[i][j]<<" ";
            
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// ================================== BETTER SOL =========================

// void setMatZero(int mat[][4], int n, int m){

//     vector<int> row(n);
//     vector<int> col(m);

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<n; j++){
//             if(mat[i][j] == 0){
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if(row[i] || col[j]){
//                mat[i][j] = 0; 
//             }
//         }
//     }
// }

// void printMat(int mat[][4], int n, int m){
//     for(int i= 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             cout<<mat[i][j]<<", ";
//         }
//         cout<<endl;
//     }
// }

// int main(){
//     int mat [4][4] = {
//                             {1, 1, 1, 1}, 
//                             {1, 0, 0, 1}, 
//                             {1, 1, 0, 1},
//                             {1, 1, 1, 1}};
//             int m = 4, n = 4;
   
//     setMatZero(mat, n, m);
//     printMat(mat, n, m);
        

//     return 0;
// }



// ================================= OPTIMAL SOL =========================


void setZeroMat(int mat[][4], int n, int m){

    // int row[n] = {0] ==> mat[..][0];
    // int col[m] = {0} ==> mat[0][..];

    int col0 = 1;
    for(int i = 0; i<n; i++){
        for(int j= 0; j<m; j++){
            if(mat[i][j] == 0){
                if(j != 0){                     
                    mat[0][j] = 0;
                }else{
                    col0 = 0;
                }
                mat[i][0] = 0;
            }
        }
    }

    for(int i = 1; i<n; i++){
        for(int j = 1; j<m; j++){
            if(mat[i][j] != 0){
                // check where 1st row or 1st col is 0
                if(mat[0][j] == 0 || mat[i][0] == 0){
                    mat[i][j] = 0;
                }
            }
        }
    }

    // check for 1st row
    if(mat[0][0] == 0){
        for(int j = 0; j<m; j++){
            mat[0][j] = 0;
        }
    }
    if(col0 == 0){
        for(int i =0; i<n; i++){
            mat[i][0] = 0;
        }
    }

}


void printMat(int mat[][4], int n, int m){
    for(int i= 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<mat[i][j]<<", ";
        }
        cout<<endl;
    }  
    
}



int main(){

    int mat [4][4] = {
                    {1, 1, 1, 1}, 
                    {1, 0, 0, 1}, 
                    {1, 1, 0, 1},
                    {1, 1, 1, 1}};


    setZeroMat(mat, 4, 4);
    printMat(mat, 4, 4);

     
    return 0;
}