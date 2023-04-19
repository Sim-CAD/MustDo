    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int s = digits.size();
        for(int i = s-1 ; i >=0 ; i--){
            if(digits[i] < 9){
                digits[i] ++;
                break;
            }else{
                digits[i] = 0;
            }
        }
        if(digits[0] == 0){
            ans.push_back(1);
        }

        for(int i = 0; i < s; i++){
            ans.push_back(digits[i]);
        }
        return ans;
    }