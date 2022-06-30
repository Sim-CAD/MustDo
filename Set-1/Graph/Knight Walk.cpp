	
 //Problem Name: Knight Walk
 //Source : GeeksForGeeks
 /****************************************/
    int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int kx = KnightPos[0] - 1;
	    int ky = KnightPos[1] - 1;
	    int tx = TargetPos[0] - 1;
	    int ty = TargetPos[1] - 1;
	    
	    
	    if(kx == tx && ky == ty)
	     return 0;
	     
	    	    
	    queue<pair<int, int>> q;
	    vector<vector<int>>vis(N, vector<int>(N, 0));
	    int ans = 0;
	    
	    q.push({kx , ky});
	    vis[kx][ky] = 1;
	    
	 
	    
	    while(!q.empty()){
	        int size = q.size();
	        ans++;
	        
	        while(size !=0){
	            pair<int, int> p = q.front();
	            q.pop();
	            
	            int xx = p.first;
	            int yy = p.second;
	            
	            int ax[] = {1, 1, -1, -1, 2, -2, 2, -2};
	            int ay[] = {2, -2, 2, -2, 1, 1, -1, -1};
	            
	            for(int i = 0; i < 8; i++){
	                int nx = xx + ax[i];
	                int ny = yy + ay[i];
	                
	                if(nx == tx && ny == ty){
	                    return ans;
	                }
	                
	                if(nx >= 0 && ny >=0 && nx < N && ny < N && vis[nx][ny] == 0){
	                     vis[nx][ny] = 1;
	                    q.push({nx, ny});
	                   
	                }
	            }
	            size --;
	        }
	    }
	    return ans;
	}