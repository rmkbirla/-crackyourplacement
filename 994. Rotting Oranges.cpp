class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int minutes=0;
        bool flag=false;
        while(!q.empty()){
            flag =true;
            int s=q.size();
            while(s--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            if(j<m-1 && grid[i][j+1]==1){
                grid[i][j+1]=2;
                q.push({i,j+1});
            }
            if(i<n-1 && grid[i+1][j]==1){
                grid[i+1][j]=2;
                q.push({i+1,j});
            }
            if(j>0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1});
            }
            if(i>0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j});
            }
            }
            minutes++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(flag)
         return minutes-1;
        else
          return minutes;
    }
};
