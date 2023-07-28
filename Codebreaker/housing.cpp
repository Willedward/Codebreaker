#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k)
{
	if(n < k) return 0;
	if(n < 2*k) return 1;
	int res = 1;
	for(int i = k; i<n; i++)
	{
		res += solve(n-i, i);
	}
	return res;
}


int main()
{
	int n;
	cin>>n;
	cout<<solve(n, 5);
}
