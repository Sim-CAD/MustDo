 /*****************************
  Problem name: Smallest subarray with sum greater than x
  Source: GeeksForGeeks 
  ******************************/
    
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int start = 0;
        int end = 0;
        int minLength = n + 1; //Invalid 
        int sum = 0;
        
        while(end < n){
            while(sum <= x && end < n){
                sum += arr[end++];
            }
            
            while(sum > x && start < n){
                if(end - start < minLength){
                    minLength = end - start;
                }
                sum -= arr[start++];
            }
        }
            
            
        return minLength;
    }