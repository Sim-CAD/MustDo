//Problem Name: Square root of a number
//Source : GeeksForGeeks
/****************************************/
long long int floorSqrt(long long int x) 
    {
    int l = 1;
    int h = x;
    long long int ans = 0;
    while(l <= h){
       long long int mid = l + (h - l) / 2;
        
        if(mid*mid == x)
            return mid;
        
       else if(mid*mid > x){
            h = mid - 1;
        }
        
       else if(mid*mid < x){
            ans = mid;
            l = mid + 1;
        }
    }
    return ans; 
    }