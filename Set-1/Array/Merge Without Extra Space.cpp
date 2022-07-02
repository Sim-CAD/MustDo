        int nextGap(int gap){
                if(gap <= 1)
                    return 0;
                return ceil(gap/2.0);
            }
            
        void print(long long* arr, int n){
            for(int i = 0; i< n; i++){
                cout << arr[i]<<" ";
            }
            cout <<endl;
        }
            
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            long int i = n - 1, j = 0;
            
            //Method 1: Swap and sirt with time complexity O((n+m)log(n+m))
            //Space complexity : O(1)
    
            while(i >= 0 && j < m){ //->O(n+m)
                 if(arr1[i] > arr2[j])
                    swap(arr1[i], arr2[j]);
                i--;
                j++;
            }
            //Time complexity : O(nlog(n) + mlog(m))
            sort(arr1, arr1 + n);
            sort(arr2, arr2 + m);
            
            
            //Method 2 : Gap Algorithm
            
            int gap = ceil(n+m)/2.0;
           
            for(; gap >= 1; gap = nextGap(gap)){
              //  cout <<"Gap: "<<gap<<endl;
                int i, j;
                for(i = 0; i + gap < n; i++){
                    if(arr1[i] > arr1[gap+i])
                        swap(arr1[i], arr1[gap+i]);
                }
                // cout << "After Step 1 "<<endl;
                // print(arr1, n);
                // print(arr2, m);
                
                for(j = gap > n ? gap - n : 0; i < n && j < m; i++, j++){
                      if(arr1[i] > arr2[j])
                        swap(arr1[i], arr2[j]);
                }
                
                // cout << "After Step 2 "<<endl;
                // print(arr1, n);
                // print(arr2, m);
                
                if(j < m){
                    for(j = 0; j + gap < m; j++){
                        if(arr2[j] > arr2[j+gap])
                            swap(arr2[j], arr2[j+gap]);
                    }
                }
                // cout << "After Step 3 "<<endl;
                // print(arr1, n);
                // print(arr2, m);
            }
    
        } 
};