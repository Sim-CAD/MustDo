 
  	
 //Problem Name: 621. Task Scheduler
 //Source : LeetCode
 /****************************************/
 int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>freq;
        //Count the frequency as we are applying Greedy Approach
        for(char t: tasks){
            freq[t]++;
        }
        
        priority_queue<int>pq;
        //Add the the frequency in priority queue
        //as this data strucure will help to choose max frequency
        for(auto i: freq){
            pq.push(i.second);
        }
        
        int res = 0;
        
        //Process until the priority queue is not empty
        while(!pq.empty()){
            int cycle = 0;
            //Temperory vector to remove the data from the queue and add to this vector and 
            //later if the count is not to 0 the add back to the queue with the updated value
            vector<int> templist;
            for(int i = 0; i < n + 1; i++){
                if(!pq.empty()){
                    templist.push_back(pq.top() - 1);//Adding and updating the frequency
                    pq.pop();
                    cycle++;
                }
            }
            
            //Check the templist, if anything is remainig
            for(auto t : templist){
                if(t)pq.push(t);
            }
            
            if(pq.empty()){
                res = res+cycle;
            } else{
                res = res+n+1;
            }
        }
        return res;
    }