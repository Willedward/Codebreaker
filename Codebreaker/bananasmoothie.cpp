#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e10;
int main()
{
	int n, k; cin>>n>>k;
	vector<long long> v;
	for(int i = 0; i < n; i++)
	{
		ll a; cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	int z = 0;
	ll maks = INF;
	ll counter = 0;
	if(n < k) return 0;
	for(int i = 0; i < n; i++)
	{
	    z++;
	    if(v[i] < 0) break;
		if(z == k)
		{
		    
			maks = min(maks, v[i]);
			z = 0;
			//cout<<"maks': "<<maks<<endl;
			counter = counter+maks;
			//cout<<"counter': "<<counter<<endl;
			maks = INF;
			//maks = min(maks, v[i]);
		}
		if(z < k)
		{
			maks = min(maks, v[i]);
		}
		//z++;
		//cout<<"z: "<<z<<endl;
		//cout<<"maks: "<<maks<<endl;
		//cout<<"counter: "<<counter<<endl;
	}
	cout<<counter;
}
