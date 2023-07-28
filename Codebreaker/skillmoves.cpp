#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//typedef push_back pb;
typedef pair<ll, ll> pll;
int main()
{
	int n, k;cin>>n>>k;
	vector<ll> v, f;
	bool pri = false;
	for(int i = 0; i < n; i++)
	{
		ll a; cin>>a;
		v.push_back(a);
		if(a == 0) pri = true;
	}
	for(int i = 0; i < n; i++)
	{
		ll b; cin>>b;
		f.push_back(b);
	}
	//vector<pair<ll, ll>> p1;
	priority_queue<pll, vector<pll>, greater<pll>> p;
	for(int i = 0; i < n; i++)
	{
		p.push({v[i], f[i]});
	}
	//sort(p.begin(), p.end());
	//ll counter = k;
	ll sum = 0;
	priority_queue<ll> pq;
	for(int i = 0; i < k; i++)
	{
	    //cout<<"p[i].first: "<<p[i].first<<endl;
	    while(!p.empty()){
		if(sum >= p.top().first)
		{
			pq.push(p.top().second);
			p.pop();
			//cout<<"p[i]: "<<p[i].second<<endl;
		}else break;
	    }
		if(!pq.empty())
		{
		    sum+=pq.top();
		    pq.pop();
		}
		
	}
	//cout<<"size: "<<pq.size()<<endl;
	//if(!pri) { cout<<0; return 0;}
	
	cout<<sum;
	
}


