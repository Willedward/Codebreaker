#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k; cin>>n>>k;
	vector<int> v;
	for(int i =0 ; i < n; i++)
	{
		int a;
		cin>>a;
		v.push_back(a);
	}
	vector<int> dp(n+10);
	dp[0] = 0;
	for(int i = 1; i < n; i++)
	{
		int temp = abs(v[i-1] - v[i])+dp[i-1];
		for(int j = 2; j <= k; j++)
		{
			if(i-j >= 0)
			{
			    //cout<<"i: "<<i<<" j: "<<j<<endl;
				temp = min(temp, abs(v[i-j]-v[i]) + dp[i-j]);
				//cout<<temp<<endl;
			}
		}
		dp[i] = temp;
	}
	//for(int i =0 ; i < n; i++) cout<<dp[i]<<" ";
	//cout<<endl;
	cout<<dp[n-1];
}
