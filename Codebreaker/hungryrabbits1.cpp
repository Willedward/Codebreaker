#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	v = vector<int> (n+2, 0);
	int mark = 0, maks = -1;
	for(int i = 1; i <= n; i++)
	{
		int s;
		cin>>s;
		v[i] = s;
		if(s != 0)
		{
		    mark = 1;
		}
	}
	int temp = 0;
	for(int i = n; i>=1; i--)
	{
	    if(v[i] != 0)
	    {
		temp = max(n-i, i-1);
	    maks = max(maks, (temp + v[i]));
	    //cout<<"maks: "<<maks<<endl;
	    }
	    }
	if(mark==0)
	{
	    maks = 0;
	}
	cout<<maks;
}
