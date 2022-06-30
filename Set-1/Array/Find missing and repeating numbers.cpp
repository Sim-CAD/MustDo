int *findTwoElement(int *arr, int n) {
       int* ans;
    /*
    *Method 1
    */

      for(int i = 0; i < n; i++){
          int x  = abs(arr[i]) - 1; //get the corresponding position
          if(arr[x] < 0)
              ans[0] = x + 1; //Repeating number
          else
              arr[x] *= -1; //Make it negative
           
      }
       
      for(int i = 0 ; i < n; i++){
          if(arr[i] > 0)
              ans[1] = i+1; //Missing number
           
      }
    
    /*
    Method 2 : USING XOR
    */
    
    int x = 0;
    for(int i = 0; i < n; i++){
        x = x ^ arr[i];
        x = x ^ (i + 1);
    }
    
    
    //Get set bit 
    //(n) , in (n-1) the last bit LSB right side until first 1 all the value will be inverted
    //n = 100101100 then n-1 = 100101011 and ~(n-1) = 011010100
    //To ge last bit : do n & ~(n-1)
    
    int setbit = x & (~ (x - 1));
    
     ans[0] = 0;
     ans[1] = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] & setbit)//5 & 1 = nonzero
            ans[0] = ans[0] ^ arr[i];
        else
            ans[1] = ans[1] ^ arr[i];
            
        if((i + 1) & setbit)
            ans[0] = ans[0] ^ (i+1);
        else
            ans[1] = ans[1] ^ (i+1);
    }
        
    for(int i = 0; i < n; i++){
        if(arr[i] == ans[0])
            break;
        if(arr[i] == ans[1]){
            int tmp = ans[0];
            ans[0] = ans[1];
            ans[1] = tmp;
            break;
        }
     
    }
       
       return ans;
    }