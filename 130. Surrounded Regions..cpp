class Solution {
public:
    void check(int i,int j,vector<vector<char>>& board){
        if(board[i][j]=='-') board[i][j]='O';
        else return;
         
        if(j<board[0].size()-1)
            check(i,j+1, board);
        if(i< board.size()-1)
            check(i+1,j,board);
        if(j>0)
            check(i,j-1,board);
        if(i>0)
            check(i-1,j,board);
        
           
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='-';
                }
            }
        }
        
        for(int j=0;j<board[0].size();j++){
                if(board[0][j]=='-'){
                    check(0,j,board);
                }
            }
        for(int i=1;i<board.size();i++){
                if(board[i][0]=='-'){
                    check(i,0,board);
                }
            }
        for(int j=1;j<board[0].size();j++){
                if(board[board.size()-1][j]=='-'){
                    check(board.size()-1,j,board);
                }
            }
         for(int i=1;i<board.size()-1;i++){
                if(board[i][board[0].size()-1]=='-'){
                    check(i,board[0].size()-1,board);
                }
            }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='-'){
                    board[i][j]='X';
                }
            }
        }
    }
};
