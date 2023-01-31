  void helper(vector<int> nums, vector<int>& ans, int l, int h){
      
        if( l > h)
            return;
            
        int m = (l+h)/2;
        
        ans.push_back(nums[m]); //preorder
        
        helper(nums, ans, l, m - 1);
        helper(nums, ans, m + 1, h);
        
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> ans;
        int l = 0;
        int h = nums.size() - 1;
        helper(nums, ans, l, h);
        return ans;
    }