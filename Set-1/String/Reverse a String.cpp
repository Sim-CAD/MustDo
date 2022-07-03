	 //Problem Name: Reverse a String 
 //Source : GeeksForGeeks
 /****************************************/
void reverse(string str, string &res){
 =
    for(int i = 0; i< str.size(); i++)
        cout<<str[i]<<" ";
   
    if(str.size() == 0)
        return;
    reverse(str.substr(1), res);
    res.push_back(str[0]);
}

string reverseWord(string str){
    string res;
  reverse(str, res);
  return res;
}