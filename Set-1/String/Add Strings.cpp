  //Problem Name:  Add Strings
 //Source : LeetCode
 /****************************************/
 string addStrings(string num1, string num2) {
        int n1 = num1.size() - 1;
        int n2 = num2.size() - 1;
        
        int sum = 0;
        int carry = 0;
        string ans;
        
        while(n1 >= 0 || n2 >= 0){
            if(n1 < 0){
                sum   = (num2[n2] - 48) + carry;
                ans.push_back(sum % 10 + 48);
                carry = sum / 10;
                n2--;
            }
            else if(n2 < 0){
               sum = (num1[n1] - 48) + carry;
               ans.push_back(sum % 10 + 48);
               carry = sum / 10;
               n1--; 
            }
            else{
                sum = (num1[n1] - 48) + (num2[n2] - 48) + carry;
                ans.push_back(sum % 10 + 48);
                carry = sum / 10;
                n1--;
                n2--;
            }
        }
        if(carry)
            ans.push_back(carry+48);
        
        reverse(ans.begin(), ans.end());
        return ans;    
    }