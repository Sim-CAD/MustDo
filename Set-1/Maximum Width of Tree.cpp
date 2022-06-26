 //Problem Name: Maximum Width of Tree
 //Source : GeeksForGeeks
 /****************************************/
int getMaxWidth(Node* root) {
        
        if(root == NULL)
            return 0;

        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        int ans = 0;
        
        while(!q.empty()){
            
            int size = q.size();
            
            int minIndexOfLevel = q.front().second;
           
           int last = 0, first = 0;
            
            for(int i=0; i < size; i++){
                int curIndex = q.front().second - minIndexOfLevel;
                Node* node = q.front().first;
                
                q.pop();
                
                if(i == 0) first = curIndex;
                
                if(i == size-1) last = curIndex;
                
                
                if(node -> left)
                    q.push({node->left, curIndex * 2 + 1});
                
                if(node->right)
                    q.push({node->right, curIndex * 2 + 2});
                    
                
                
            }
           
            ans = max(ans, size);
        }
        return ans;
    }