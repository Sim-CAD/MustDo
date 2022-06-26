
 //Problem Name: Rat in a Maze Problem - I 
 //Source : GeeksForGeeks
 /****************************************/
 void RatMaze(vector<vector<int>> &maze, vector<vector<int>> &vis, int n, int x, int y, vector<string>& result, string s){
        
         if(x < 0 || y < 0 || x >= n || y >= n || maze[x][y] == 0|| vis[x][y] == 1)
            return;
            
        if(x == n - 1 && y == n - 1){
            result.push_back(s);
            return;
        }
         
            vis[x][y] = 1 ; //visited
            RatMaze(maze, vis, n , x+1, y, result, s+"D");
            RatMaze(maze, vis, n , x-1, y, result, s+"U");
            RatMaze(maze, vis, n , x, y+1, result, s+"R");
            RatMaze(maze, vis, n , x, y-1, result, s+"L");
            
            vis[x][y] = 0; //backtracking
   
       
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>res;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string s = "";
        if(m[0][0] == 0)
            return {};
        RatMaze(m, vis, n, 0, 0, res, "");
        return res;
  
  
    }