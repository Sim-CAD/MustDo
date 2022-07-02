 //Problem Name: Sort an array of 0s, 1s and 2s
 //Source : GeeksForGeeks
 /****************************************/
void sort012(int a[], int n)
    {
        if(n == 0) return;
        
        int i = 0;
        int j = 0;
        int k = n - 1;
        
        while(k >= i){
            if(a[i] == 2){
                swap(a[i], a[k--]);
            }else if(a[i] == 0){
                swap(a[i], a[j++]);
                i++;
            }else{
                i++;
            }
        }
    }