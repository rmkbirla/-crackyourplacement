lass Solution {
public:
      void check(int i,int j,vector<vector<char>>& board){
        if(board[i][j]=='1') board[i][j]='0';
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
    int numIslands(vector<vector<char>>& board) {
        int count=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='1'){
                    check(i,j, board);
                    count++;
                }
            }
        }
        return count;
    }
};
