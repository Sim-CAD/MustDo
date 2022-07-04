//Problem Name: Search in a Rotated Array
 //Source : GeeksForGeeks
 /****************************************/
int search(int A[], int l, int h, int key){
        int mid;
        while(l <= h){
             mid = (l + h ) / 2;
             
             if(A[mid] == key)
                 return mid;
             
             //Left side is sorted
             else if(A[l] <= A[mid]){
                if(key >= A[l] && key <= A[mid])
                    h = mid -1;
                else
                    l = mid + 1;
             }
             //If right side is sorted
             else{
                 if(key >= A[mid] && key <= A[h])
                    l = mid + 1;
                
                else
                    h = mid - 1;
             }
       }
       return -1;
    }