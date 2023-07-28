#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ll n, m;cin>>n>>m;
	bool k[n+10];
	for(int i = 0; i <= n+5; i++) k[i] = 0;
	for(int i = 0; i < m; i++)
	{
		ll a; cin>>a;
		k[a] = 1;
	}
	ll dp[n+10];
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		if(k[i] == 0)
		{
			if(i <= 1) dp[i] = dp[i-1];
			else{
				dp[i] = dp[i-1] + dp[i-2];
				dp[i] = dp[i]%1000000007;
			}
		}
		else dp[i] = 0;
	}
	cout<<dp[n];
}
