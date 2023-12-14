class Solution {
public:
    bool isSafe(int row, int cols, vector<vector<int>>& board, int n){
        int i = row, j = cols;

        //left row check
        while(j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            j--;
        }

        //upper left diagonal check
        i = row; j = cols;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            i--; j--;
        }

        //bottom left diagonal
        i = row; j = cols;
        while(i < n && j >= 0){
            if(board[i][j] == 1){
                return false;
            }
            i++; j--;
        }

        return true;
    }


    int solve(vector<vector<int>>& board, int n, int cols, int& count){
        //base case
        if(cols >= n){
            count++;
            return count;
        }

        //ek case solve kardo
        for(int row=0; row<n; row++){
            if(isSafe(row, cols, board, n)){
                board[row][cols] = 1;
                solve(board, n, cols+1, count);
                board[row][cols] = 0;
            }
        }

        return count;
    }

    int totalNQueens(int n) {
        // if(n <= 3){
        //     return 0;
        // }
        int count = 0;
        vector<vector<int>> board(n, vector<int>(n, 0));
        return solve(board, n, 0, count);
    }
};