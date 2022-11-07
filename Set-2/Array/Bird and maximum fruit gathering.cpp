  /*****************************
  Problem name: Bird and maximum fruit gathering
  Source: GeeksForGeeks 
  ******************************/
int maxFruits(int arr[],int n,int m)
    {
        int sum = 0;
        int ans = INT_MIN;
        int j = 0;
        
        for(int i = 0 ; i < m; i++){
            sum += arr[i];
        }
        
        ans = max(ans, sum);
        
        for(int i = m; i < n; i++){
            sum += arr[i];
            sum -= arr[j];
            j++;
            if(j == n) j = 0;
            ans = max(ans, sum);
        }
        
         for(int i = 0; i < m; i++){
            sum += arr[i];
            sum -= arr[j];
            j++;
            if(j == n) j = 0;
            ans = max(ans, sum);
        }
    return ans;
    }