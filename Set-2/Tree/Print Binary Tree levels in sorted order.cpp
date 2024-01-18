       /*********************************************
     * GeeksForGeeks:Print Binary Tree levels in sorted order
     * Youtube: NA
    */
    
    vector <vector <int>> binTreeSortedLevels (int arr[], int n)
    {
        queue<int>q;
        vector<vector<int>> ans;
        
        q.push(0);
        
        while(!q.empty()){
            int s = q.size();
            vector<int>levl;
            while(s--){
                int front = q.front();
                q.pop();
                
                levl.push_back(arr[front]);
                
                // left child is at index (2*i + 1) and 
                // right child is at index (2*i + 2) in the array. 
                
                if(2 * front + 1 < n) q.push(2 * front + 1);
                
                if(2 * front + 2 < n) q.push(2 * front + 2);
                
            }
            sort(levl.begin(), levl.end());
            ans.push_back(levl);
        }
        return ans;
        
    }