#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin>>m>>n;
	int dp[m+5][n+5];
	int coins[m+2];
	int val[m+2];
	//cout<<"h";
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
		    //cout<<"k";
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		int a, b; cin>>a>>b;
		coins[i] = a;
		val[i] = b;
	}
	//cout<<"g";
	for(int i = 1; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
		    //cout<<"j: "<<j<<" coins[i] "<<coins[i]<<endl;
		    dp[i][j] = dp[i-1][j];
			if(j - coins[i] >= 0)
			{
				dp[i][j] = max(dp[i-1][j-coins[i]] + val[i], dp[i-1][j]);
				//cout<<dp[i][j]<<endl;
			}
		}
	}
	/*
	for(int i = 1; i <= m; i++)
	{
	    for(int j = 1; j <= n; j++)
	    {
	        cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}
	*/
	
	
	cout<<dp[m][n];
}
