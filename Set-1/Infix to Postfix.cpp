   //Problem Name: Infix to Postfix
 //Source : GeeksForGeeks
 /****************************************/
  int precFun(char ch){
        if(ch == '^')
            return 3;
        
        else if(ch == '*' || ch == '/')
            return 2;
        
        
        else if(ch == '+' || ch == '-')
            return 1;
        
        else
            return -1;//For open brackets
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string res ;
        stack<char> st;
        
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                res = res+s[i];
            
            else if(s[i] == '(')
                st.push(s[i]);
            
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    res= res+st.top();
                    st.pop();
                }
                if(!st.empty())
                    st.pop();
            }
            
            else {
                while(!st.empty() && precFun(st.top()) >= precFun(s[i])){
                    res = res + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }
        
      return res;  
    }
