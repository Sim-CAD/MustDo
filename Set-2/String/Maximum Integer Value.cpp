  /*****************************
  Problem name: Maximum Integer Value
  Source: GeeksForGeeks 
  ******************************/
 long long int MaximumIntegerValue(string S) {
        
        long long int res = S[0] - '0';
        
        for(int i = 1; i < S.size(); i++){
            int nextItem = S[i] - '0';
            
            res = max(res + nextItem, res * nextItem);
        }
        return res;
    }