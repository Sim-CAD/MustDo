 
 //Problem Name:Min distance between two given nodes of a Binary Tree
 //Source : GeeksForGeeks
 /****************************************/
    Node* LCA(Node* root, int a, int b){
        if(root == NULL)
            return NULL;
            
        if(root->data == a || root->data == b)
            return root;
        
        Node* left = LCA(root->left, a, b);
        
        Node* right = LCA(root->right, a, b);
        
         if(left == NULL && right == NULL)
            return NULL;
        
        if(left != NULL && right != NULL)
            return root;
            
        if(left != NULL)
            return LCA(root->left, a, b);
            
        if(right != NULL)
            return LCA(root->right, a, b);
    }
    
    int helper(Node* lca, int k, int initialDis){
        if(lca == NULL)
            return -1;
            
        if(lca->data == k)
            return initialDis;
        
        int left = helper(lca->left, k , initialDis+1);
        
        if(left != -1) return left;
        
        return helper(lca->right, k, initialDis+1);
    }
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
       if(root == NULL)
        return 0;
        
        int initialDis = 0;
        Node* lca = LCA(root, a, b);
        
        int d1 = helper(lca, a, initialDis);
        int d2 = helper(lca, b, initialDis);
        
        return d1+d2;
    }