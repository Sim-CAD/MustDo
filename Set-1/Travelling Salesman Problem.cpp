 //Problem Name: Travelling Salesman Problem (Hamiltonian Cycle)
 //Source : GeeksForGeeks
 /****************************************/
int helper(vector<vector<int>>cost, int n, vector<vector<int>> &dp, 
          int current_city, int mask){
  
    if(mask == (1 << n) - 1)
        return cost[current_city][0];
    
    if(dp[mask][current_city] != -1)
        return dp[mask][current_city];
    
      int ans = INT_MAX;
        for(int newcity = 0; newcity < n; newcity++){
            if((mask & (1 << newcity)) == 0){
            int newAns = cost[current_city][newcity] + 
                         helper(cost, n, dp, newcity, mask | (1<<newcity));
            ans = min(ans, newAns);
                                                   
            }
    }
    return dp[mask][current_city]= ans;
}

int total_cost(vector<vector<int>>cost){
  int n = cost.size();
  int mask = 1;
  vector<vector<int>> dp ((1<<n), vector<int>(n, -1));
  int res = helper(cost, n, dp,0,mask);
  return res;
  
}