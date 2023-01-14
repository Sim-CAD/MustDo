int getCount(Node *root, int l, int h)
    {
      if(root == NULL)
        return 0;
        
      if(root->data >= l && root->data <= h){
          int left = getCount(root->left, l , h);
          int right = getCount(root->right, l, h);
          return 1 + left + right;
      }
      
      else if(root-> data < l){
          int right = getCount(root->right, l , h);
          return right;
      }
      
      else if(root->data > h){
          int left = getCount(root->left, l, h);
          return left;
      }
      
     return 0;
    }