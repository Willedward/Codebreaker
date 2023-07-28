#include <bits/stdc++.h>

using namespace std;
signed main()
{
	int n, m;
	cin>>n>>m;
	int arr[n+1][m+1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin>>arr[i][j];
		}
	}
	int low = 1, high = 1e9;
	long long ans = 0;
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		int check = 0, count = 0; 
		long long v[m+2];
		for(int i = 1; i <= m; i++) v[i] = 0;
		for(int i = 1; i <= n; i++)
		{
			count = 0;
			for(int j = 1; j<=m; j++)
			{
				if(arr[i][j] >= mid)
				{
					count++;
					v[j]++;
				}
				if(count >= 2) check = 1;
			}
		}
		int counter = 0;
		for(int i = 1; i<=m; i++) counter += min(1ll, v[i]);
		if(counter < m || check == 0) high = mid-1;
		else {
		low = mid+1;
		ans = mid;
	}
	//cout<<ans;
}
cout<<ans;
}
