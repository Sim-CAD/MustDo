void connect(Node *root)
    {
        
      queue<Node*> q;
      
      if(root == NULL)
        return;
        
      q.push(root);
      
      while(!q.empty()){
        int s = q.size();
        Node* prev = NULL;
        
        for(int i = 0; i < s; i++){
            
            Node* curr = q.front();
            q.pop();
        
            if(prev != NULL){
                prev->nextRight = curr;
            }
            prev = curr;
            if(curr->left != NULL)
            q.push(curr->left);
            
            if(curr->right != NULL)
            q.push(curr->right);
            
        }
      }
    } 