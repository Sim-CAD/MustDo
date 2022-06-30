 
  //Problem Name: Product array puzzle
 //Source : GeeksForGeeks
 /****************************************/
 vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        vector<long long int> res(n, 1);
        
        for(int i = 1; i < n; i++){
            res[i] = res[i - 1]*nums[i - 1];
        }
        
       long long int rightProduct = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            res[i] = res[i]*rightProduct;
            rightProduct = rightProduct * nums[i];
        }
        
        return res;
    }