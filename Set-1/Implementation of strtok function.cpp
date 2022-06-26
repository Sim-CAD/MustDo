 //Problem Name: Implementation of strtok function
 //Source : GeeksForGeeks
 /****************************************/
#include<bits/stdc++.h>
using namespace std;

char* mystrtok(char* s, char d) {
    
  static char* input =  NULL;
   
  if(s != NULL)
    input = s;
    
  if(input == NULL)
     return NULL;
  
    
  char* res = new char[strlen(input)+1];
     
    int i =0;
    
    for(; input != '\0'; i++){
        if(input[i] != d)
           res[i] = input[i]; 
        
        else{
            res[i] = '\0';
            input = (i+1 < strlen(input)) ? input+i+1 : NULL;
            return res;
        }
    }
    
    res[i] = '\0';
    input = NULL;
    
    
    return res;
    
}


int main()
{
    char str[90] = "Implementation of strtok function";
      char* ptr = mystrtok(str, ' ');
      while(ptr){
        ptr = mystrtok(NULL, ' ');
        cout <<ptr<<endl; 
      }

   
	return 0;
}

      
   
    
  