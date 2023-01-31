int pIdx = 0;
    Node* helper(int in[], int pre[], int is, int ie){
        if(is > ie)
            return NULL;
        
        Node* root = new Node(pre[pIdx]);
        pIdx++;
        
        int inIdx = 0;
        for(int i = is; i <= ie; i++){
            if(root->data == in[i]){
                inIdx = i;
                break;
            }
        }
        
        root->left = helper(in, pre, is, inIdx-1);
        root->right = helper(in, pre, inIdx+1, ie);
        
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        Node* ans = helper(in, pre, 0, n-1);
        return ans;
    }