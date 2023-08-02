int calcdist(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited,vector<vector<int>>& dp) {
    int n=grid.size();
    int m=grid[0].size();
      if(dp[i][j] != -1 && dp[i][j]!=1073741823) return dp[i][j];
    if (grid[i][j] == 1) {
        return 0;
    }

    visited[i][j] = true;
     int u=INT_MAX/2,l=INT_MAX/2,d=INT_MAX/2,r=INT_MAX/2; 
    
  if (j < m - 1 && !visited[i][j + 1])
        r = 1 + calcdist(grid, i, j + 1, visited, dp);
    if (i < n - 1 && !visited[i + 1][j])
        d = 1 + calcdist(grid, i + 1, j, visited, dp);
     if (j > 0 && !visited[i][j - 1])
        l = 1 + calcdist(grid, i, j - 1, visited, dp);
   if (i > 0 && !visited[i - 1][j])
        u = 1 + calcdist(grid, i - 1, j, visited, dp);


    visited[i][j] = false;

    return dp[i][j]= min(r, min(d,min(l,u)));
}

vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> result(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
     vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
                result[i][j] = calcdist(grid, i, j, visited,dp);
        
        }
    }

    return result;
}

