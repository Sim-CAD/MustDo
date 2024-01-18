       /*********************************************
     * GeeksForGeeks:Level order traversal Line by Line
     * Youtube: NA
    */
    
vector<vector<int>> levelOrder(Node* node)
{
  queue<Node*> q;
  vector<vector<int>> ans;
  
  q.push(node);
  
  while(!q.empty()){
      int s = q.size();
      vector<int> lev;
      while(s--){
          Node* front = q.front();
          q.pop();
          
          lev.push_back(front->data);
         
          if(front->left) q.push(front->left);
          if(front->right) q.push(front->right);
      }
      ans.push_back(lev);
  }
  return ans;
}