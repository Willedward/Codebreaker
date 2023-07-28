#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x;
	cin>>n>>x;
	vector<vector<int>> v(n+10);
	for(int i = 0; i < x; i++)
	{
		int s, e; cin>>s>>e;
		v[e].push_back(s);
	}
	int dp[n+10];
	dp[0] = 0;
	//cout<<"dp[0]: "<<dp[0]<<endl;
	for(int i = 0; i <= n+3; i++)dp[i] = 0;
	//for(int i = 0; i < n; i++) cout<<dp[i]<<" ";
	//cout<<"v[0]: "<<v[0].size()<<endl;
	for(int i = 1; i < n; i++)
	{
	    
		if(v[i].size() == 0)
		{
			dp[i] = dp[i-1] + 1; 
		}else
		{	
			int temp = 1e8;
			for(int j = 0; j < v[i].size(); j++)
			{
				temp = min(temp, dp[v[i][j]]);
			}
			dp[i] = temp+1;
		}
		//cout<<dp[i]<<endl;
	}
	//for(int i = 0; i < n; i++) cout<<dp[i]<<" ";
	//cout<<endl;
	cout<<dp[n-1];
}
