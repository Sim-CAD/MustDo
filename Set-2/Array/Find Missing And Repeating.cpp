 int *findTwoElement(int *arr, int n) {
        int* ans = new int[2];
        
        for(int i =0; i < n; i++){
            int x = abs(arr[i]) - 1;
            
            if(arr[x] > 0){
                arr[x] *=-1;
            }
            else{
                ans[0] = x + 1;
            }
        }
        
         for(int i =0; i < n; i++){
            
             
            if(arr[i] > 0){
                ans[1] = i + 1;
                break;
            }
        }
        
        return ans;
    }