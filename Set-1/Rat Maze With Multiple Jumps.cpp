    
 //Problem Name: Rat Maze With Multiple Jumps
 //Source : GeeksForGeeks
 /****************************************/
    bool dfs(vector<vector<int>> &m, vector<vector<int>> &ans, int x, int y){
        
        int n = m.size();
        
        if(x >= n || y >= n) 
            return false;
       
      
        if(x == n-1 && y == n-1){
            ans[x][y] = 1;
            
             return true;
        }
        
        ans[x][y] = 1;
    
        for(int steps = 1; steps <= m[x][y] && steps < n ; steps++){
           if(dfs(m, ans, x, y + steps)) return true ;
           if(dfs(m, ans, x + steps, y)) return true;
        }
         
        ans[x][y] = 0;
        return false;
   
    }
    
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    
        vector<vector<int>> ans(n, vector<int>(n, 0));
        
        if(dfs(matrix, ans, 0, 0))
          return ans;
        else
        return {{-1}};
     
	}