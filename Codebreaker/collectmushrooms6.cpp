#include <bits/stdc++.h>

using namespace std;

int main()
{
	int r, c, d, k; cin>>r>>c>>d>>k;
	char grid[r+2][c+2];
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			cin>>grid[i][j];
		}
	}
	int dp[r+4][c+4];
	for(int i = 0; i <= r+1; i++)
	{
		for(int j = 0; j<=c+1; j++)
		{
			dp[i][j] = 0;
		}
	}
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			//cout<<grid[i][j]<<" ";
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
			if(grid[i][j] == 'S') dp[i][j] +=1;
		}
		//cout<<endl;
	}
	int counter = 0;
	for(int i = 1; i <= r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			if(grid[i][j] == 'M')
			{
				int l = dp[min(i+d, r)][min(j+d, c)] - dp[min(r, i+d)][max(j-d-1, 0)] - dp[max(0, i-d-1)][min(c, j+d)] + dp[max(0, i-d-1)][max(0,j-d-1)];
				//cout<<"l: "<<l<<endl;
					if(l >= k) counter+=1;
			}
		}
	}/*
	for(int i = 1; i <= r; i++)
	{
	    for(int j = 1; j <= c; j++)
	    {
	        cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}*/
	cout<<counter<<endl;
	
}
