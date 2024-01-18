   /*********************************************
     * GeeksForGeeks:Binary Tree to BST
     * Youtube: https://www.youtube.com/watch?v=iSZOcOe_TE4
    */


 void inorder(Node* root, vector<int>& data){
      if(root == NULL) return;
      inorder(root->left, data);
      data.push_back(root->data);
      inorder(root->right, data);
  }
  void update(Node* root, vector<int> sortedData, int& i){
      if(root == NULL) return;
      update(root->left, sortedData, i);
      root->data = sortedData[i++];
      update(root->right, sortedData, i);
  }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> data;
        int i = 0;
        inorder(root, data);
        sort(data.begin(), data.end());
        update(root, data, i);
        return root;
    }