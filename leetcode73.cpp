#include<iostream>
#include<vector>
using namespace std;



// ==================================BRUTE FORCE METHOD=========================
void markRow(int mat[][4], int i){
    int m = 4;
    for(int j = 0; j<m; j++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}

void markCol(int mat[][4], int j){
    int n = 4;
    for(int i = 0; i<n; i++){
        if(mat[i][j] != 0){
            mat[i][j] = -1;
        }
    }
}

int main(){

    int mat [4][4] = {
                    {1, 1, 1, 1}, 
                    {1, 0, 0, 1}, 
                    {1, 1, 0, 1},
                    {1, 1, 1, 1}};
    int m = 4, n = 4;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 0){
                markRow(mat, i);
                markCol(mat, j);
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == -1){
                mat[i][j] = 0;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
           cout<<mat[i][j]<<" ";
            
        }
        cout<<endl;
    }
    return 0;
}