struct TrieNode{
    TrieNode* link[26];
    bool isLeaf;
};

class Solution
{
    
public:
   
    void insert (string &s, TrieNode* root){
        TrieNode* curr = root;
        for(int i =0; i <s.length(); i++){
             int k = s[i] - 'a';
             if(curr->link[k] == NULL){
                 TrieNode* n = new TrieNode();
                 curr->link[k] = n;
             }
             curr = curr->link[k];
        }
        curr->isLeaf = true;
    }
    
    bool exist(string &s, TrieNode* root){
        TrieNode* curr = root;
        
        for(auto &i: s){
            int k = i - 'a';
            if(curr->link[k] == NULL){
                return false;
            }
            curr =  curr->link[k];
            if(curr->isLeaf == false)
                return false;
        }
        return true;
    }
    
    string longestString(vector<string> &words)
    {
        TrieNode* root  = new TrieNode();
        int s = words.size();
         string longest = "";
        
        for(int itr = 0; itr < s; itr++){
            insert(words[itr], root);
        }
       
         for(int itr = 0; itr < s; itr++){
            if(exist(words[itr], root)){
                if(words[itr].length() > longest.length()){
                    longest = words[itr];
                }
                else if(words[itr].length() == longest.length() && words[itr] < longest){
                    longest = words[itr];
                }
                
            }
        }
        return longest;
    }
};