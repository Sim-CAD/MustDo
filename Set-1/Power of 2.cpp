    //Problem Name: Power of 2
    //Source : GeeksForGeeks
    /****************************************/
    bool isPowerofTwo(long long n){
        /* Method 1*/
        //Divide by 2 if leads to 1 (TRUE)
        //Divide by 2 if does not lead to non 1 number (FALSE)
        //This lead to (log2N) time complexity
        
        /*Method 2*/
        //count the set bits by anding the number by 1 (left shift for moving forward) and if the count = 1(TRUE)
        //else (FALSE)
        //Time complexity (log2N)
        
        /*Method 3*/
        //Using Bit Shift
        //Right shift the number until you hit the first one or set bit.
        //Anding the value with 1 and moving forward we don't have to left shift 1 as we are right shifting number itself.
        //If number is 1 at end (TRUE)
        //else (FALSE)
        //Time complexity (log2N)
        
        
        if(n == 0)
            return false;
            
        // if(n > 1 && ( n & 1) == 0)
        //     n >>= 1;
        
        // return (n==1) ? true : false;
        
        
        
        /*Method 4*/
        //Log Operation
        //log2(2^N) = N
        //log2(N) = integer, ceil and floor is equal (TRUE)
        //else (FALSE)
        //Time Complexity O(1)
        
        if(floor(log2(n)) == ceil(log2(n)))
            return true;
        else
            return false;
        
        
    }

