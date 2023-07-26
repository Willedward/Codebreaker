#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin>>n>>m;
	int v[m+1];
	for(int i = 0; i < m; i++)
	{
		v[i] = 0;
	}
	for(int i = 0; i < m; i++)
	{
		int c;
		cin>>c;
		v[i] = c;
	}
	sort(v, v+m);
	int counter = 0;
	while(m - counter > 0)
	{
		if(n - v[counter] >= 0){
		n = n - v[counter];
		
		counter++;
	}
		else
		{
			break;
		}
}	
cout<<counter<<'\n';
}
