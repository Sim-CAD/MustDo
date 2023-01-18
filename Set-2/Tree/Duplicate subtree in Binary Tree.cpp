map<string, int> mp;
    
    string dupSubHelper(Node* root){
        if(root == NULL)
            return "#";
            
        if(root->left == NULL && root->right == NULL)
            return to_string(root->data);
        
        string s = "";
        
        s += to_string(root->data);
        s += "#"+dupSubHelper(root->left);
        s += "#"+dupSubHelper(root->right);
        

        mp[s]++;
    
        return s;
        
    }
    int dupSub(Node *root) {
        mp.clear();
        dupSubHelper(root);
        for(auto itr:mp){
            if(itr.second >= 2){
                return 1;
            }
        }
       return 0;
       
    }