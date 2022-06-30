 //Problem Name: Maximum path sum from any node
 //Source : GeeksForGeeks
 /****************************************/
 
int helper(Node *root, int &m){
      if(root == NULL)
        return 0;
      
      int maxLeftChildSum = helper(root->left, m); 
      if(maxLeftChildSum < 0) maxLeftChildSum = 0;
      
      int maxRightChildSum = helper(root->right, m);
      if(maxRightChildSum < 0) maxRightChildSum = 0;
      
      m = max(m, maxLeftChildSum + maxRightChildSum + root->data);
      
      int maxChild = max(maxLeftChildSum, maxRightChildSum);
      
      
      return ( maxChild + root->data); //Choosing the path
  }
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        int m = INT_MIN;
       int res =  helper(root, m);
       return m;
    }