 
  //Problem Name: Parenthesis Checker
 //Source : GeeksForGeeks
 /****************************************/
 //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
           stack<char> st;
        
        for(int i = 0; i < x.length(); i++){
            if(x[i] == '(' || x[i] == '{' || x[i] == '['){
                st.push(x[i]);
            }
            else if(x[i] == ')' || x[i] == '}' || x[i] == ']'){
                if(st.empty())
                    return false;
                if(x[i] == ')' && st.top() != '(')
                    return false;
                if(x[i] == '}' && st.top() != '{')
                    return false;
                if(x[i] == ']' && st.top() != '[')
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        return false;
    }