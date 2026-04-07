// transpose of matrix

#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> transpose(vector<vector<int>> &matrix){
    int n = matrix.size();      //rows
    int m = matrix[0].size();   //columns per row

    vector<vector<int>>ans (m, vector<int> (n));        //created one vector to store transposed matrix

    for(int i = 0; i<n; i++){
        for(int j =i; j<m; j++){
            ans[j][i] = matrix[i][j];
        }
    }
    return ans;

}


int main(){
    vector<vector<int>> mat = {{2,4,-1},
                              {-10,5,11},
                              {18,-7,6}};

    vector<vector<int>> result = transpose(mat);
    // print result
    for(auto row : result){
        for(auto val : row){
            cout << val << "  ";
        }
        cout << endl;
    }
    return 0;
}