#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	int sa[a+500], sb[b+500], sc[c+500], sd[d+500];
	for(int i = 1; i <= a; i++) cin>>sa[i];
	for(int j = 1; j <= b; j++) cin>>sb[j];
	for(int i = 1; i <= c; i++) cin>>sc[i];
	for(int j = 1; j <= d; j++) cin>>sd[j];
	vector<int> rab, rcd, rab1, rcd1;
	vector<pair<int, int>> r1, r2;
	map<int, bool> m;
	map<int, pair<int, int>> m1;
	for(int i = 1; i <= a; i++)
	{
		for(int j = 1; j <= b; j++)
		{
			int res1 = sa[i] + sb[j];
			rab.push_back(res1);
			rab1.push_back(res1);
			m[res1] = 1;
			m1[res1] = {sa[i], sb[j]};
		}
	}
	for(int i = 1; i <= c; i++)
	{
		for(int j = 1; j<= d; j++)
		{
			int res = sc[i] + sd[j];
			//cout<<res<<" ";
			if(m[-res] == 1)
			{
				//cout<<res<<endl;
				cout<<m1[-res].first<<" "<<m1[-res].second<<" "<<sc[i]<<" "<<sd[j];
				return 0;
			}
		}
	}
	
}
