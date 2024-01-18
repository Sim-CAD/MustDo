    /*********************************************
     * GeeksForGeeks:Height of Binary Tree
     * Youtube: NA
    */
 int height(struct Node* node){
        if(node == NULL) return NULL;
        
        int lh = height(node->left);
        int rh = height(node->right);
        
        return 1 + max(lh, rh);
    }