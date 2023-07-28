#include <bits/stdc++.h>

using namespace std;

int main()
{
	int h, w;
	cin>>h>>w;
	char arr[h+5][w+5];
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++){
		char a; cin>>a;
		arr[i][j] = a;
		}
	}
	long long dp[h+5][w+5];
	for(int i = 0; i <= h+1; i++)
	{
		for(int j = 0; j <= w+1; j++){
		dp[i][j] = 0;
		}
	}
	dp[1][1] = 1;
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
		    if(j == 1 && i == 1)
		    {
		        continue;
		    }
			if(arr[i][j] == '.')
			{
				long long k = dp[i-1][j] + dp[i][j-1];
				
				dp[i][j] = k%1000000007;
				//cout<<dp[i][j]<<endl;
			}
		}
	}
	long long g = dp[h][w];
	//cout<<g<<endl;
	cout<<g%1000000007;
	
	
}




