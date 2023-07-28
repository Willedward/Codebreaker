#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ll h, n;
	cin>>h>>n;
	vector<ll> v;
	long long dp[n+5];
	for(int j = 0; j < n; j++)
	{
		ll a; cin>>a;
		v.push_back(a);
	}
	ll nil = 0;
	dp[0] = v[0];
	ll ps = dp[0], idx = 0, ls = dp[0];
	for(int j = 1; j < n; j++)
	{
		dp[j] = dp[j-1] + v[j];
		//ps = max(ps, dp[j]);
		if(dp[j] > ps)
		{
		    ps = dp[j];
		    idx = j;
		}
	}
	//cout<<dp[n-1]<<endl;
	ll sum = 0;
	ll checker = 0;
	for(int i = 0; i < 2; i++)
	{
	for(int j = 0; j < n; j++)
	{
		sum = max(nil, sum + v[j]);
		if(sum >= h){cout<<i<<" "<<j; return 0;}
	}
		if(i == 0) checker = sum;
	}
	//cout<<"dp[n-1]: "<<dp[n-1];
	if(dp[n-1] <= 0) {cout<<"-1 -1"; return 0;}
	else{
	//bool check = false;
	ll i;/*
	for(int k = 0; k < n; k++){
		sum = max(nil, sum + dp[k]);
	}
	*/
	i = (h-checker-ps) / dp[n-1];
	ll p = i*dp[n-1];
	//cout<<"i: "<<i<<endl;
	ll total = max(p+checker-dp[n-1], checker);
	i = max(nil, i-1);
	//cout<<"p: "<<p<<endl;
	//cout<<"i': "<<i<<endl;
	//cout<<"total: "<<total<<endl;
	/*
	for(int k = 0; k < n; k++)
	{
	    total += v[k];
	    if(total >= h) 
	    {
	        cout<<i<<" "<<k; return 0;
	    }
	}
	//i+=1;
	*/
	
	while(true){
	    i+=1;
	for(ll k = 0; k < n; k++)
	{
		total += v[k];
		//cout<<total<<endl;
		if(total >= h)
		{
		    
			cout<<i<<" "<<k; return 0;
		}
	}
	}
	    
	}
	/*
	if(dp[0] == 0){ cout<<"-1 -1"; return 0;}
	else{
	i = h/dp[0];
	if(h % dp[0] == 0) i--;
	
	}
	//cout<<"-1 -1";
	*/
}
