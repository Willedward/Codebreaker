#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
// m -> n; count -> k; 
long long memo[3][3100][3100];
long long solve(int n, int k, int count, int bin, int m)
{
	if(m == n)
	{
		return 1;
	}
	ll sum = 0;
	if(memo[bin][count][m] != -1) return memo[bin][count][m]%998244353;
	else{
	if(k-count == 1) sum = solve(n, k, 0, 0, m+1)%998244353;
	else sum = (solve(n, k, 0, 0, m+1) + solve(n, k, count+1, bin, m+1))%998244353;	
	memo[bin][count][m] = sum%998244353;
	return sum%998244353;
	}
}

int main()
{
	int n, k;
	cin>>n>>k;
	for(int i = 0; i < 2; i++)
	{
	    for(int j = 0; j <= k+2; j++)
	    {
	        for(int f = 0; f <= n+2; f++)
	        {
	            memo[i][j][f] = -1;
	        }
	    }
	}
	cout<<(solve(n, k, 0, 0, 1) + solve(n, k, 1, 1, 1))%998244353;
}
