 bool findPath(Node* root, vector<Node*> &path, int n){
        
        if(root == NULL)
            return false;
            
        path.push_back(root);
        
        if(root->data == n)
            return true;
        
        if(findPath(root->left, path, n) || findPath(root->right, path, n))
            return true;
            
        path.pop_back();
        return false;
        
    }
    
    
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       vector<Node*> p1, p2; //Path for n1 and n2 respectively
       
       if(!findPath(root, p1, n1) || !findPath(root, p2, n2))
        return NULL;
        
       Node* ans = NULL;
       
       for(int i = 0 ; i < p1.size() && i < p2.size(); i++){
           if(p1[i] == p2[i])
            ans = p1[i];
       }
       return ans;
    }