#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long v[n+2];
	for(int i = 0; i < n; i++)
	{
		cin>>v[i];
	}
	long long dp[n+2][2];
	dp[0][0] = 0;
	dp[0][1] = v[0];
	for(int i = 1; i < n; i++)
	{
		dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
		dp[i][1] = dp[i-1][0] + v[i];
		//cout<<"h";
	}
	cout<<max(dp[n-1][0], dp[n-1][1]);
}
