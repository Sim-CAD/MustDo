 //Problem Name: Implementation of atoi function
 //Source : GeeksForGeeks
 /****************************************/
#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s){
   int res = 0;
   int sign = 1;
   int i = 0;
   
   if(s[0] == '-'){
       sign = -1;
       i++;
   }
   
   while(i < s.length()){
       res = res*10 + s[i] - '0';
       i++;
   }
   
   return res*sign;
}

int main()
{
    string s = "-1234";
    //Convert string to integer
    cout<<myAtoi(s);
	return(0);
}
