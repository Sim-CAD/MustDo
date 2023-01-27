int helper(Node* root, int &ans){
        
        if(root == NULL)
            return 0;
            
        int left = helper(root->left, ans);
        int right= helper(root->right, ans);
        
        left = (left < 0) ? 0: left;
        right = (right <0) ?0:right;
        
        ans = max(ans, left + right + root->data);
        
        return (max(left, right) + root->data);
        
    }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        int ans = INT_MIN; 
        helper(root,ans);
        return ans;
    }