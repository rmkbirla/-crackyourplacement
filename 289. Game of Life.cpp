
class Solution {
public:
     int checkN(int i, int j, vector<vector<int>>& board) {
    int c = 0;
    int rows = board.size();
    int cols = board[0].size();

    if (i > 0)
        if (board[i - 1][j] == 1)
            c++;
    if (j > 0)
        if (board[i][j - 1] == 1)
            c++;
    if (i < rows - 1)
        if (board[i + 1][j] == 1)
            c++;
    if (j < cols - 1)
        if (board[i][j + 1] == 1)
            c++;
    if (i > 0 && j > 0)
        if (board[i - 1][j - 1] == 1)
            c++;
    if (i < rows - 1 && j < cols - 1)
        if (board[i + 1][j + 1] == 1)
            c++;
    if (i > 0 && j < cols - 1)
        if (board[i - 1][j + 1] == 1)
            c++;
    if (i < rows - 1 && j > 0)
        if (board[i + 1][j - 1] == 1)
            c++;

    return c;
}

    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> v;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==0){
                     if(checkN(i,j,board)==3){
                         v.push_back({i,j});
                     }
                }
                if(board[i][j]==1){
                    if(checkN(i,j,board)<2){
                        v.push_back({i,j});
                    }
                else if(checkN(i,j,board)>3){
                        v.push_back({i,j});
                    }
                }
            }
        }
        for(int i=0;i<v.size();i++){
            if(board[v[i].first][v[i].second]==0){
                board[v[i].first][v[i].second]=1;
            }else{
                board[v[i].first][v[i].second]=0;
            }
        }
    }
};
