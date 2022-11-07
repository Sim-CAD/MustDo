 /*****************************
  Problem name: Multiply two strings
  Source: GeeksForGeeks 
  ******************************/
string multiplyStrings(string s1, string s2) {
        
        
        if(s1 == "0" || s2 == "0")
            return "0";
            
        string ans;
        
        
        if(s1[0] == '-' && s2[0] == '-'){
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        }
        
        else if(s1[0] != '-' && s2[0] == '-'){
            s2 = s2.substr(1);
            ans.push_back('-');
        }
        
        else if(s1[0] == '-' && s2[0] != '-'){
            s1 = s1.substr(1);
            ans.push_back('-');
        }
       
        
        int len1 = s1.size();
        int len2 = s2.size();
        

        vector<int> res(len1 + len2, 0);
        
        for(int i = len1-1; i >= 0; i--){
            for(int j = len2-1; j >= 0; j--){
              res[i+j+1] += (s1[i] - '0') * (s2[j] - '0');
              res[i+j] += res[i+j+1]/10;
              res[i+j+1] = res[i+j+1]%10;
              
            }
        }
    
        int i = 0; //Remove extra 0s
        while(i < res.size() && res[i] == 0){
            i++;
        }
        
        while(i < res.size()){
            ans.push_back(res[i] + '0');
            i++;
        }
        return ans;
    }
