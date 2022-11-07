 /*****************************
  Problem name: Subarray with given sum
  Source: GeeksForGeeks 
  ******************************/
 
 vector<int> subarraySum(int arr[], int n, long long s)
    {
        int left = 0;
        int right = 0;
        int currentSum = 0;
   
        while(left < n || right < n){
            if(currentSum < s){
                currentSum += arr[right++];
            }
           
            else if(currentSum == s && right != left){
                return {left+1, right};
            }
            else {
                currentSum -= arr[left++];
               
            }
        }
        return {-1};
    }