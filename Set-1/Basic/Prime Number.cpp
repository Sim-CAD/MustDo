//Problem Name: Prime Number Using Sieve of eratosthenes
//Source : GeeksForGeeks
/****************************************/
  int isPrime(int N){
        if(N==1)
            return false;
       
        for(int i = 2; i*i <= N; i++){
            if(N%i == 0) 
               return false;
        }
        return true;
    }

//Time complexity
//     -> For N we have N/2 prime numbers

//     {N/2 + N/3 + N/5 + N/7 + ... + N/P}, P = largest primenumber <= N
//    = N{1/2 + 1/3 + 1/5 + 1/7 + ... + 1/P} 
//    = N * Harmonic Progression of Sum
//    = N * loglogN;
//    = NloglogN