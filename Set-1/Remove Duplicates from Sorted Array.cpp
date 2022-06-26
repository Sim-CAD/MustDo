 

  //Problem Name: Remove Duplicates from Sorted Array
 //Source : GeeksForGeeks
 /****************************************/
 int removeDuplicates(vector<int>& nums) {
        
        int i = 0; // will help to keep unique numbers in front
        int j =  1; // finds the unique number
        
    while (j < nums.size()){
            
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
       return i+1; 
    }