 /*****************************
  Problem name: Implement strstr
  Source: GeeksForGeeks 
  ******************************/
int strstr(string s, string x)
{
    int n = s.size();
    int m = x.size();
    int i = 0,j = 0;

   
    for(i = 0; i <= (n-m); i++){
        bool isTrue = true;
        for(j = 0; j < m; j++){
            if(x[j] != s[i+j]){
                isTrue = false;
                break;
            }
           
        }
        
        if(isTrue == true){
            return i;
        }
       
    }
     return -1;
}