#include<iostream>
#include<vector>
using namespace std;

void spiralMatrix(vector<vector<int>> &mat, int n, int m){
    int srow = 0, scol = 0;
    int erow = n-1, ecol = m-1;

    while(srow<=erow && scol<=ecol){
        for(int j = scol; j<=ecol; j++){
            cout<<mat[srow][j]<<" ";
        }
        for(int j = srow+1; j<=erow; j++){
            cout<<mat[j][ecol]<<" ";
        }
        for(int j = ecol-1; j>=scol; j--){
            if(srow == erow) break;
            cout<<mat[erow][j]<<" ";
        }
        for(int j = erow-1; j>=srow+1; j--){
            if(scol == ecol) break;
            cout<<mat[j][scol]<<" ";
        }

        srow++;
        scol++;
        erow--;
        ecol--;
        
    }

    
}

int main(){ 
    vector<vector<int>> mat = { {1,2,3,4},
                                {5,6,7,8},
                                {9,10,11,12}};

    int n = mat.size();
    int m = mat[0].size();

   spiralMatrix(mat,n,m);
    

    return 0;
}