  /*****************************
  Problem name: Minimum Depth of a Binary Tree
  Source: GeeksForGeeks 
  ******************************/
 int minDepth(Node *root) {
        if(root == NULL)
            return 0;
        
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        int ldepth = INT_MAX;
        int rdepth = INT_MAX;
        
        if(root->left){
            
            ldepth = minDepth(root->left);
        }
       
       if(root->right){
            rdepth = minDepth(root->right);
       }
             return (min(ldepth, rdepth) + 1);
    }
       
      