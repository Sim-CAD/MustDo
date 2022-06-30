  //Problem Name:  Maximum Subarray
 //Source : LeetCode
 /****************************************/

 int maxSubArray(vector<int>& nums) {
        
        int maxSum = nums[0];
        int curr_sum = maxSum;
        
        for(int i = 1 ; i < nums.size(); i++){
            curr_sum = max(nums[i], nums[i]+curr_sum);
            maxSum = max(maxSum, curr_sum);
        }
        return maxSum;
    }