vector <int> postOrder(Node* root)
{
  if(root == NULL)
    return {NULL};
    
   stack<Node*> s ;
   vector<int> ans;
   Node* curr = root;
   
   while(curr != NULL || !s.empty()){
       
       if(curr != NULL){
           s.push(curr);
           curr = curr->left;
       }
       
       else{
           Node* tmp = s.top() -> right;
           
           if(tmp == NULL){
              tmp = s.top();
              s.pop();
              ans.push_back(tmp->data);
              
              while(!s.empty() && tmp == s.top()->right){
                  tmp = s.top();
                  s.pop();
                  ans.push_back(tmp->data);
              }
           }
           else{
               curr = tmp;
           }
       }
   }
   return ans;
}
