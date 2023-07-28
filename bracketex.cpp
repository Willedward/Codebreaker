#include <bits/stdc++.h>

using namespace std;

bool validator(char b, char a)
{
	if( a == '(' &&  b == ')')
	{
		return true;
	}else if ( a == '{' && b == '}'){
		return true;
	}else if( a == '[' &&  b == ']')
	{
		return true;
	}else return false;
}


int main()
{
	int n;
	cin>>n;
	vector<char> l;
	bool pr = false;
	for(int i = 0; i < n; i++)
	{
		//cout<<"i: "<<i<<endl;
		char b;
		cin>>b;
		if(b == '{' || b == '(' || b == '['){
		//cout<<"p1: "<<endl;
		//cout<<"b1: "<<b<<endl;
		l.push_back(b);
	}
	else{
		//cout<<"b: "<<b<<" l[s-1]: "<<l[l.size()-1]<<endl;
		if(l.size()>0){
		if(validator(b, l[l.size()-1])){ 
			l.pop_back();
		}else {pr = true; break;
		}
	}
		else {pr = true; break;}
		
	}
	//cout<<endl;
	}
	if(pr || l.size() != 0) cout<<"Invalid";
	else cout<<"Valid";
	return 0;
	
}
