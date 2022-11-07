  /*****************************
  Problem name: Activity Selection(Greedy)
  Source: GeeksForGeeks 
  ******************************/
 int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>vec;
       for(int i = 0; i < n; i++){
           vec.push_back({end[i], start[i]});
       }
       
       sort(vec.begin(), vec.end()); //sort using end
       
       
       int activity = 1;
       int e = vec[0].first;
       
       for(int i = 1; i < n; i++){
           if(vec[i].second > e){
               activity++;
               e = vec[i].first;
           }
       }
       return activity;
    }