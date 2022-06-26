   //Problem Name: Find number of closed islands
 //Source : GeeksForGeeks
 /****************************************/

  void dfs(vector<vector<int>>& m, int i, int j, int N, int M){
        
        if( i < 0 || i >= N || j < 0 || j >= M || m[i][j] == 0)
            return;
        
        m[i][j] = 0;
        
        dfs(m, i+1, j, N, M);
        dfs(m, i-1, j, N, M);
        dfs(m, i, j+1, N, M);
        dfs(m, i, j-1, N, M);
    
    }
    
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(i*j == 0 || i == n-1 || j == m-1){
                    if(matrix[i][j] == 1) {//Convert land into water
                        dfs(matrix, i, j, N, M);
                       // matrix[i][j] = 0;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << matrix[i][j]<<" ";
            }
            cout <<endl;
        }
        
         for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){ //count Lands
                    count++;
                    dfs(matrix, i, j, N, M);
                }
            }
        }
        return count;
    }