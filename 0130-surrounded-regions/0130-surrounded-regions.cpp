class Solution {
public:
    bool checkborder(int i,int j,int n,int m){
        return (i==n-1 && j<m) || (j==0 && i<n) || (i==0 && j<m) ||(j==m-1 && i<n);
    }
    bool check(int i,int j,int n,int m){
        return i>-1 && i<n && j>-1 && j<m;
    }
    void Bfs(vector<vector<char>>& board,int i,int j){
        int n=board.size();
        int m=board[0].size();
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            i=q.front().first;
            j=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
               if(check(i+row[k],j+col[k],n,m) && board[i+row[k]][j+col[k]]=='O'){
                   board[i+row[k]][j+col[k]]='1';
                   q.push({i+row[k],j+col[k]});
               }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && checkborder(i,j,n,m)){
                   board[i][j]='1';
                   Bfs(board, i, j);
                }
            }
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                   board[i][j]='X';
                }
                else if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
         }
    }
};