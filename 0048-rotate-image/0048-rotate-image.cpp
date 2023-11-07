class Solution {
public:
    void rotate(vector<vector<int>> &matrix){
        vector<vector<int>> temp=matrix;
        int row=matrix.size(),col= matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                matrix[j][row-i-1]=temp[i][j];
            }
        }
    }
};