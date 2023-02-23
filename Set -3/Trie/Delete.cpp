/*Complete the function below
Node is as follows:
struct trie_node
{
    int value; // non zero if leaf
    trie_node_t *children[ALPHABET_SIZE];
};*/
class Solution{
  public:
  void deleteKey(trie_node_t *root, char key[])
  {
    for(int i = 0; key[i] != '\0'; i++){
        int k = key[i] - 'a';
        if(root->children[k] != NULL){
          root->children[k]->value = 0;
        }
        root = root->children[k];
    }
  }