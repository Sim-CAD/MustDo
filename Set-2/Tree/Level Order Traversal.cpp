vector<int> levelOrder(Node* node)
    {
      queue<Node*> q;
      vector<int> ans;
      
      if(node == NULL)
        return {NULL};
    
      q.push(node);
      
      while(!q.empty()){
          Node*tmp = q.front();
          q.pop();
          ans.push_back(tmp->data);
          
          if(tmp->left)
            q.push(tmp->left);
        
          if(tmp->right)
            q.push(tmp->right);
      }
      return ans;
    }