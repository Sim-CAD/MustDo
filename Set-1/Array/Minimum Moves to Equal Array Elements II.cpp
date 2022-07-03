//Problem Name: Minimum Moves to Equal Array Elements II
 //Source : LeetCode
 /****************************************/
 
 
  //Make the array equal to the median in this case it is 1
    0   0  1  6  8
    0+x          8-y //Add something in left and subtract in right in order to make them equal.
    i.e 0 + x = 8 - y;
    = x+y = 8; (this is the required number of steps)
    */
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int moves = 0;
        while(i < j){
            moves += nums[j] - nums[i];
            i++;
            j--;
        }
    return moves;
        
    }