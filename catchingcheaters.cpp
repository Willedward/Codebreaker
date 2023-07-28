#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c, d;
	cin>>c>>d;
	string a, b; cin>>a>>b;
	int lcs[c+5][d+5];
	//vector<char> f, g;
	//f.push_back('a');
	//g.push_back('a');
	//for(int i = 0; i < c; i++) f.push_back(a[i]);
	//for(int i = 0; i < d; i++) g.push_back(b[i]); 
	for(int i = 0; i <= c; i++)
	{
		for(int j = 0; j <= d; j++)
		{
			if(i == 0 || j == 0) lcs[i][j] = 0;
			else
			{
				if(a[i-1] == b[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
				else
				{
					lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
				}
			}
		}
	}
	// the dp
int    dp[c+3][d+2];
	for(int i = 0; i <= c+1; i++)
	{
	    for(int j = 0; j <= d+1; j++)
	    {
	        dp[i][j] = 0;
	    }
	}
int maks = 0;
	for(int i = 1; i <= c; i++)
	{
		for(int j = 1; j <= d; j++)
		{
			if(a[i-1] == b[j-1])
			{
				dp[i][j] = dp[i-1][j-1] + 2;
				//cout<<"k: "<<dp[i][j]<<endl;
				maks = max(maks, dp[i][j]);
			}
			else
			{
			    dp[i][j] = max(0, max(dp[i-1][j], dp[i][j-1])-1);
				//dp[i][j] = max(dp[i-1][j], dp[i][j-1])-1;
				maks = max(dp[i][j], maks);
			
			}
		}
	}
	//cout<<"lcs:"<<endl;
	/*
	for(int i = 1; i <= c; i++)
	{
	    for(int j = 1; j <= d; j++)
	    {
	        cout<<lcs[i][j]<<" ";
	    }
	    cout<<endl;
	}*//*
	cout<<"dp: "<<endl;
	for(int i = 1; i <= c; i++)
	{
	    for(int j = 1; j <= d; j++)
	    {
	        cout<<dp[i][j]<<" ";
	    }
	    cout<<endl;
	}*/
	cout<<maks;
	
	
}
