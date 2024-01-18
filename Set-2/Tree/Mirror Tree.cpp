   /*********************************************
     * GeeksForGeeks:Mirror Tree
     * Youtube: https://www.youtube.com/watch?v=vdwcCIkLUQI
    */

     // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node != NULL){
            mirror(node->left);
            mirror(node->right);
            
            Node* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        return;
    }