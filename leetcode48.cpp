// Rotate image at 90 degree

#include<iostream>
#include<vector>
#include <algorithm>


using namespace std;


void transpose(vector<vector<int>> &matrix){
    int n = matrix.size();      //rows
    int m = matrix[0].size();   //colums

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // reversed the matrix
    for(int i = 0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

    // print matrix
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
};


int main(){
    vector<vector<int>> mat = {{2,4,-1},
                              {-10,5,11},
                              {18,-7,6}};

    transpose(mat);
};