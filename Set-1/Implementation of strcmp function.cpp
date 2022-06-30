 //Problem Name: Implementation of strcmp function
 //Source : GeeksForGeeks
 /****************************************/

#include<bits/stdc++.h>
using namespace std;

int my_strcmp(string s1, string s2){
    int len1 = s1.length();
    int len2 = s2.length();
    
    int len = (len1 > len2) ? len1 : len2;
    int i = 0;
    while(i<=len){
        if((int)s1[i] > (int)s2[i])
            return 1;
        if((int)s2[i] > (int)s1[i])
            return -1;
        if(i == len1-1 && i == len2-1)
            return 0;
        i++;
    }
}
int main()
{

	string s1 = "HELLO1";
	string s2 = "Hello4";
	
	//s1 > s2 , return 1
	//s1 < s2, return -1
	//s1==s2, return 0
	
	cout << my_strcmp(s1, s2);
	return(0);
}
