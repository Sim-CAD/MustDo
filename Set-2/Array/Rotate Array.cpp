/*Solution 1: GeeksForGeeks*/
//Algorithm:A Juggling Algorithm
    
    //Time Complexity: O(log(min(a,b)))
    int gcd(int a, int b){ //Will help us to find the number of sets in the array arr
        if(b == 0)
            return a;
        else
            return gcd(b, a%b);
    }
    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n){
        for(int i = 0; i < gcd(n,d); i++){
            int j = i;
            int x = arr[i]; //store the first element of each set
            while(1){
                int k = (j + d) % n;
                if(k == i)
                    break;
                arr[j] = arr[k];
                j = k;
            }
            arr[j] = x;
        }
    }

    //-------------------------------------------------------------------------------------------------------------------

    /*Solution 2: LeetCode*/
     void rotate(vector<int>& nums, int k) {

       k = k % nums.size();
       reverse(nums.begin(), nums.end());
       reverse(nums.begin(), nums.begin() + k);
       reverse(nums.begin() + k, nums.end());
    }