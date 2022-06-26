 //Problem Name: Longest valid Parentheses
 //Source : GeeksForGeeks
 /****************************************/
    int maxLength(string S){
       stack<char>ch;
       stack<int>invalid_id;
       int len = 0;
       invalid_id.push(-1);
       
       for(int i = 0; i < S.length(); i++){
           
           if(S[i] == '('){
               
               invalid_id.push(i); //Assuming we won't get corresponding closing brackets
               ch.push(S[i]);
               
           }
           else{
                if(!ch.empty() && ch.top() == '('){
                    invalid_id.pop(); //We found the match
                    ch.pop();
                    len = max(len, i - invalid_id.top());
                }
                 else{
                    invalid_id.push(i); //Problem index
                }
               
          }
       }
       return len;
    
    }