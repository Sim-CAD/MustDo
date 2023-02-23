// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    for(auto i : key){
        int k = i - 'a';
        if(root->children[k] == NULL){ //Insert
            TrieNode* n = new struct TrieNode();
            root->children[k] = n;
        }
        //Move to the new node
        root = root->children[k];
    }
    root->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
   for(auto i : key){
       int k = i - 'a';
       if(root->children[k] == NULL){ //Not found
           return false;
       }
       else{
           root = root->children[k];
       }
   }
   return root->isLeaf;
}