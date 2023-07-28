#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	long long sum = 0;
	long long maks = 0;
	for(int i = 0; i < n; i++)
	{
		char a; cin>>a;
		if(a == 'M')
		{
			long long temp;
			long long f = 0;
			temp = sum - 2;
			sum = max(f, temp);
			maks = max(maks, sum);
		}else
		{
			long long b;
			b = a - '0';
			sum+=b;
			maks = max(maks, sum);
		}
		
	}
	cout<<maks;
	
}
