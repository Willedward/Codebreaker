#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h, w;
	cin>>h>>w;
	char grid[h+4][w+4];
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			cin>>grid[i][j];
		}
	}/*
	for(int i = 1; i <= w; i++)
	{
		for(int j = 1; j <= h; j++)
		{
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
*/	int dp[h+5][w+5];
	for(int i = 0; i <= h+2; i++)
	{
		for(int j = 0; j <= w+2; j++)
		{
			dp[i][j] = 0;
		}
	}
	dp[1][1] = 1;
//	cout<<dp[1][1]<<endl;
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
		    if(i == 1 && j == 1) continue;
		    //cout<<grid[i][j]<<endl;
			if(grid[i][j] == '#')
			{
				dp[i][j] = 0;
			}
			if(grid[i][j] == '.')
			{
				dp[i][j] = dp[i-1][j]+dp[i][j-1];

			}
		///	cout<<dp[i][j]<<" ";
			dp[i][j] = dp[i][j]%(1000000007);
		}
		//cout<<endl;

	}
	cout<<dp[h][w];


}
