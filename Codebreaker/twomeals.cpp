#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ll n; cin>>n;
	vector<ll> v;
	for(int i = 0; i < n; i++)
	{
		ll a;
		cin>>a;
		v.push_back(a);
	}
	vector<ll> ps(n+5);
	vector<ll> ss(n+5);
	ll sum = 0; ll maxsum = 0;
	for(int i = 0; i < n; i++)
	{
		sum = max(0ll, sum+v[i]);
		maxsum = max(maxsum, sum);
		ps[i] = maxsum;
	}
	sum = 0; maxsum = 0;
	for(int i = n-1; i >= 0; i--)
	{
		sum = max(0ll, sum+v[i]);
		maxsum = max(sum, maxsum);
		ss[i] = maxsum;
	}
	ll ans = 0;
	for(int i = 0; i < n-1; i++)
	{
		ans = max(ans, ps[i] + ss[i+1]);
	}
	cout<<ans;
}	
