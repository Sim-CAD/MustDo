  //Problem Name: Valid Palindrome
 //Source : GeeksForGeeks
 /****************************************/
 bool isPalindrome(string s) {
        
        if(s.length() <= 1)
            return 1;
        
        int i  = 0;
        int j = s.length() - 1;
        
        while(i < j){
            
            while(i < j && !isalnum(s[i]))
                i++;
            
             while(i < j && !isalnum(s[j]))
                j--;
            
            if(i < j && tolower(s[i]) != tolower(s[j]))
                return 0;
            i++;
            j--;
        }
        return 1;
    }