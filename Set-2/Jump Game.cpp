  /*****************************
  Problem name: Jump Game
  Source: GeeksForGeeks 
  ******************************/
 int canReach(int A[], int N) {
        int reachable = 0;
        for(int i = 0; i < N; i++){
           if(reachable < i)
            return 0;
            reachable = max(reachable, A[i]+ i);
        }
     
        return 1;
    }