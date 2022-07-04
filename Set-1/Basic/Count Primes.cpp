//Problem Name: Count Primes Using Sieve of eratosthenes
//Source : GeeksForGeeks
/****************************************/
int countPrimes(int n) {
        if(n == 0)
            return 0;
        vector<bool>isPrime(n, true);
        
        isPrime[0] =isPrime[1] = false;
        
        for(int i = 2; i*i < n; i++){
            if(isPrime[i]){
            for(int j = i*i ; j < n; j = j + i)
                isPrime[j] = false;
            }
        }
        int count=0;
        for(int i = 2; i < n; i++){
           if(isPrime[i] == true)
               count++;
        }
       return count; 
    }