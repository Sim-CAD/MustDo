   //Problem Name: Is Sudoku Valid 
 //Source : GeeksForGeeks
 /****************************************/
  int isValid(vector<vector<int>> mat){
        unordered_map<int, int>row[9];
        unordered_map<int, int>col[9];
        unordered_map<int, int>grid[9];
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                int entry = mat[i][j];
                if(entry != 0 && (row[i][entry]++ > 0 || col[j][entry]++ > 0 || 
                   grid[i/3*3+j/3][entry]++ > 0))
                   return 0;
            }
        }
        return 1;
    }