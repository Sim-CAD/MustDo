   //Problem Name: Trapping Rain Water
 //Source : GeeksForGeeks
 /****************************************/
  long long trappingWater(int arr[], int n){
        
        int lmax[n];
        lmax[0] = arr[0];
        for(int i = 1; i < n; i++)
            lmax[i] = max(lmax[i - 1], arr[i]);
            
        int rmax[n];
        rmax[n-1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], arr[i]);
        
        
        long long  water = 0;
        
        for(int i = 1; i < n - 1; i++){
            water = water + min(lmax[i], rmax[i]) - arr[i];
        }
        return water;
    }