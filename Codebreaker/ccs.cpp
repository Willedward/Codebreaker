#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, q;
	cin>>n>>q;
	map<int, int> m;
	for(int i = 0; i < q; i++)
	{
		string a;
		cin>>a;
		if(a == "TRANSMIT")
		{
			int b, c; cin>>b>>c;
			auto it = m.lower_bound(b);
			if(c < it->first || it == m.end()) cout<<"YES"<<'\n';
			else cout<<"NO"<<'\n';
		}else if(a == "WAKE")
		{
			int b; cin>>b;
			m.erase(b);
		}else if(a == "SLEEP")
		{
			int b; cin>>b;
			m[b] = 1;
		}
	}
	
	
}
