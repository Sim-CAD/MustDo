 /*****************************
  Problem name: Find triplets with zero sum
  Source: GeeksForGeeks 
  ******************************/
bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr + n);
        
        
        for(int i = 0; i < n - 2; i++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0)
                    return true;
                else if(sum > 0)
                    k--;
                else
                    j++;
            }
           
        }
       return false;     
    }