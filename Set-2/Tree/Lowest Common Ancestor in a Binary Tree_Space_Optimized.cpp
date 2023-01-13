 //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       
      if(root == NULL) return NULL;
      
      if(root->data == n1 || root->data == n2)
        return root;
        
      Node* LCA1 = lca(root->left, n1, n2);
      Node* LCA2 = lca(root->right, n1, n2);
      
      if(LCA1 && LCA2)
        return root;
        
      if(LCA2 == NULL) 
        return LCA1;
    
      return LCA2;
    }