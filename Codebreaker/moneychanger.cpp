#include <bits/stdc++.h>

using namespace std;
int main()
{
	int n, v;
	cin>>n>>v;
	vector<int> money;
	money = vector<int> (n);
	for(int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		money[i] = a;
	}
	int dp[v+1];
	
	dp[0] = 0;
	//cout<<"h";
	const int INF = 1e7;
	//cout<<"v: "<<v<<endl;
	for(int i = 1; i <= v; i++)
	{
		dp[i] = INF;
		for(auto c : money)
		{
			if(i-c >= 0)
			{
				dp[i] = min((dp[i-c] + 1), dp[i]);
				//cout<<"i: "<<i<<" ";
				//cout<<dp[i]<<endl;
			}
		}
	}
	//cout<<"h";
	if(dp[v] == INF)
	{
		cout<<-1;
	}else{
	cout<<dp[v];
	}
}
