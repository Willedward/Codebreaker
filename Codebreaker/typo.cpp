#include <bits/stdc++.h>

using namespace std;

int main()
{	
	string s, t;
	cin>>s>>t;
	bool prime = false;
	if(s.size() == 1) 
	{
		if(s[0] != t[0])
		{ cout<<"No";
		 return 0;
		}else cout<<"Yes"; return 0;
	}
	bool flag = true;
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == t[i]) continue;
		if(!flag){ cout<<"No"; return 0;}
		if(s[i] != t[i])
		{
			if(s[i] == t[i+1] && t[i] == s[i+1] && i < s.size()-1) flag = false;
			else{ cout<<"No"; return 0;}
			
			i+=1;
		}
	}
	cout<<"Yes";
	
}
