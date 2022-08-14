 /*****************************
  Problem name: Roman Number to Integer
  Source: GeeksForGeeks 
  ******************************/
int romanToDecimal(string &str) {
       unordered_map<char, int> mp {{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};
                              
        int res = mp[str.back()];
        
        for(int i = str.size() - 2; i >= 0; i--){
            if(mp[str[i]] < mp[str[i + 1]]) {  //IV = 5 - 1 = 4
                res = res - mp[str[i]];
            }
            else {
                res = res + mp[str[i]]; //VI = 5 + 1 = 6
            }
            
        }
        return res;                      
    }