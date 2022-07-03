 //Problem Name:  Longest Substring Without Repeating Characters
 //Source : LeetCode
 /****************************************/
     int lengthOfLongestSubstring(string s) {
        //sliding window
        set<char> st;
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while(j < s.size()){
            auto it = st.find(s[j]);
            if(it == st.end()){ //Insert unique character
                if(j - i + 1 > maxLen)
                    maxLen = j - i + 1;
                st.insert(s[j]);
                j++; 
            }else{
               st.erase(s[i]) ; //Remove the older character
                i++;
            }
        }
        return maxLen;
    }