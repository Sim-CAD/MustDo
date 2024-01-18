    /*********************************************
     * GeeksForGeeks:Right View of Binary Tree
     * Youtube: https://www.youtube.com/watch?v=KV4mRzTjlAk
    */
    
    void helper(Node* root, vector<int>& res, int level){
        if(root == NULL)
            return;
        if(level == res.size()){
            res.push_back(root->data);
        }
        helper(root->right, res, level+1);
        helper(root->left, res, level+1);
    }
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
      vector<int> res;
      helper(root, res, 0);
      return res;
    }