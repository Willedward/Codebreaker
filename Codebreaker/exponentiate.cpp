#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

long long power(long long a, long long b, long long m)
{
	if(b == 0) return 1;
	if(b == 1) return a;
	long long temp = power(a, b/2, m);
	temp = (temp%m*temp%m)%m;
	if(b%2 == 1) temp = ((temp%m)*(a%m))%m;
	return temp;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a, b, m;
		cin>>a>>b>>m;
		cout<<power(a, b, m)<<'\n';
	}
	
	
}
