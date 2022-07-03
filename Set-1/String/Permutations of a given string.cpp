	 //Problem Name: Permutation of a given string
 //Source : GeeksForGeeks
 /****************************************/
	void helper(string S, int id, set<string> &ans){
	    if(id == S.length()-1){
	        ans.insert(S);
	        return;
	    }
	    
	    for(int i = id; i < S.length(); i++){
	        swap(S[i], S[id]);
	        helper(S, id+1, ans);
	        swap(S[i], S[id]); //backtracking
	    }
	}
	
	vector<string>find_permutation(string S){
		 set<string> ans;
		 helper(S, 0, ans);
		 vector<string>res(ans.begin(), ans.end());
		 return res;
	}