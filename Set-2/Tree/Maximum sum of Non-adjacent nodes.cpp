   unordered_map<Node*, int>mp;
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        int withNode = 0, withoutNode = 0 ;
        if(root == NULL)
            return 0;
            
        //DP
        if(mp[root])
            return mp[root];
        
        //Case1: with node: take grandchildren
        
         withNode = root->data;
        
        if(root->left){
            withNode += getMaxSum(root->left->left);
            withNode += getMaxSum(root->left->right);
        }
        
        if(root->right){
            withNode += getMaxSum(root->right->left);
            withNode += getMaxSum(root->right->right);
        }
        
        //Case2: without node: take children
        
         withoutNode +=  getMaxSum(root->left) + getMaxSum(root->right);
        
        return mp[root] = max(withNode, withoutNode);
        
    }