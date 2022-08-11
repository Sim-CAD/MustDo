 /*****************************
  Problem name: Maximum Path Sum between 2 Leaf Nodes
  Source: GeeksForGeeks 
  ******************************/
int helperFun(Node* root, int &sum){
       if(root == NULL)
        return 0;
        
        if(root->left == NULL && root->right == NULL)
            return root->data;
       
       int maxLChild = helperFun(root->left, sum);
       
       int maxRChild = helperFun(root->right, sum);
       
       int maxChild = max(maxLChild, maxRChild);
      
       
      if(root->left != NULL && root->right != NULL){
          sum = max(sum,  maxLChild + maxRChild + root->data);
          return (maxChild + root->data);
      }
  
      if(root->left == NULL){
          return (maxRChild + root->data);
      }
     
      return (maxLChild + root->data);
    
   }
 
    int maxPathSum(Node* root)
    {
       int sum = INT_MIN;
       int res = helperFun(root, sum);
      if(root->left == NULL || root-> right == NULL)
        sum = max(sum, res);
       return sum;
     
    }