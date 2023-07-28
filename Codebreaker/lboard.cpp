#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
	cin>>n>>m;
	long long psv[m+n+5][n+m+5], psh[n+5+m][n+m+5];
	ll container[n+5][m+5];
	for(int i = 0; i <= n+m+2; i++)
	{
		for(int j = 0; j <= n+m+2; j++)
		{
			psv[i][j] = 0;
			psh[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin>>container[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			psh[i][j] = psh[i][j-1] + container[i][j];
		}
	}
	
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			psv[i][j] = psv[i][j-1] + container[j][i];
		}
	}
	long long maks = -1e18;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			ll totalh = -1e18;
			ll totalv = -1e18;
			for(int k = 1; k <= j; k++)
			{
				totalh = max(totalh, psh[i][j] - psh[i][k-1]);
			}
			for(int k = m; k >= j; k--)
			{
				totalh = max(totalh, psh[i][k] - psh[i][j-1]);
			}
			for(int k = 1; k <= i; k++)
			{
				totalv = max(totalv, psv[j][i] - psv[j][k-1]);
			}
			for(int k = n; k>=i; k--)
			{
				totalv = max(totalv, psv[j][k] - psv[j][i-1]);
			}
			//ll totalh = max(psh[i][j] - psh[i][0], psh[i][m]-psh[i][j-1]);
			//ll totalv = max(psv[j][i] - psv[j][0], psv[j][n]-psv[j][i-1]);
			//cout<<"totalh: "<<totalh<<" totalv: "<<totalv<<" container: "<<container[i][j]<<endl;
			maks = max(maks, totalh + totalv - container[i][j]);
			//cout<<"maks: "<<maks<<endl;
		}
	}
	cout<<maks;
}

//2 2
//8 1
//3 4
