/*****************************
  Problem name: Total Decoding Messages
  Source: GeeksForGeeks 
******************************/
    int CountWays(string str){
		   vector<int> dp(str.size(), -1);
		    return fun(str, 0, dp);
		   
		}
		
		int fun(string str, int i, vector<int> &dp){
		    long long mod = 1e9+7;
		    if(i >= str.length())
		        return 1;
		  
		    else if(str[i] == '0')
		        return 0;
		        
		    else if(i == str.length() - 1)
		        return 1;
		        
		    else if(dp[i] != -1)
		        return dp[i];
		  
		    else if(str[i] == '1' || (str[i] == '2' && (str[i+1] >= '0' && str[i+1] <= '6')))
		        return dp[i] = (fun(str, i + 1, dp) + fun(str, i + 2, dp)) % mod;
		    
		        return dp[i] = fun(str, i+1, dp) % mod;
		}
