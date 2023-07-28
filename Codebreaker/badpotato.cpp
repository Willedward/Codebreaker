#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin>>n;
	vector<ll> v;
	for(int i = 0; i < n; i++)
	{
		ll a; cin>>a;
		v.push_back(a);
	}
	ll dp[n+5];
	ll p = 0;
	dp[0] = max(p, v[0]);
	ll maks = 0;
	for(int i = 1; i < n; i++)
	{
	    if(v[i] == -1) dp[i] = 0;
	    else{
		dp[i] = max(dp[i-1]+v[i], p);
	    }
		maks = max(maks, dp[i]);
	}
	cout<<maks;
	
}
