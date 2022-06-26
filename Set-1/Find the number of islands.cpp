
    
 //Problem Name: Find the number of islands
 //Source : GeeksForGeeks
 /****************************************/

void helper(vector<vector<char>>& grid, int x, int y){
      int n = grid.size();
      int m = grid[0].size();
      
      if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != '1')
        return;
    
      grid[x][y] = '2'; //visited
      
      helper(grid, x+1, y);
      helper(grid, x-1, y);
      helper(grid, x, y+1);
      helper(grid, x, y-1);
      helper(grid, x+1, y+1);
      helper(grid, x-1, y-1);
      helper(grid, x+1, y-1);
      helper(grid, x-1, y+1);
      
  }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int count = 0;
        
        for(int i = 0 ; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                count++;
                helper(grid, i, j);
               }
            }
            
        }
       return count;
    }