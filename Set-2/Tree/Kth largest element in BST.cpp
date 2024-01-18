     /*********************************************
     * GeeksForGeeks: Kth largest element in BST
     * Youtube: https://www.youtube.com/watch?v=Zra0mE7M2hE
    */
  Node* preorder(Node* root, int K, int& cnt){
        if(root == NULL) return NULL;
        
        Node* node = preorder(root->right, K, cnt);
        if(node) return node;
        cnt++;
        if(K == cnt)
            return root;
        return preorder(root->left, K, cnt);
    }
    
    int kthLargest(Node *root, int K)
    {
        int cnt = 0;
        Node* res = preorder(root, K, cnt);
        return res ? res->data : -1;
    }