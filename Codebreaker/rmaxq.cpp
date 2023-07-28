#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree[4*100000+10];
ll lazy[4*100000+10];
ll mini = -1e10;
void build(ll s, ll e, ll ind, vector<ll> &v)
{
	//if(s > e) return;
	if(s == e)
	{
		tree[ind] = v[s];
		return;
	}
	ll mid = (s + e)/2;
	build(s, mid, ind*2+1, v);
	build(mid+1, e, ind*2+2, v);
	tree[ind] = max(tree[ind*2+1], tree[ind*2+2]);
}

long long query(ll s, ll e, ll ind, ll qs, ll qe)
{
	if(lazy[ind] != 0)
	{
		tree[ind] = tree[ind] + lazy[ind];
		if(s != e){
		lazy[ind*2+1] += lazy[ind];
		lazy[ind*2+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if(qs > e || qe < s || s > e) return -1e10;
	if(qs <= s && qe >= e)
	{
		return tree[ind];
	}
	ll mid = (s+e)/2;
	return max(query(s, mid, ind*2+1, qs, qe), query(mid+1, e, ind*2+2, qs, qe));
}

void update(ll s, ll e, ll qs, ll qe, ll diff, ll ind)
{
	if(lazy[ind] != 0)
	{
		tree[ind] = tree[ind] + lazy[ind];
		if(s != e)
		{
			lazy[ind*2+1] += lazy[ind];
			lazy[ind*2+2] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	if(qs > e || qe < s || s>e)
	{
		return;
	}
	if(qs <= s && qe >= e)
	{
		tree[ind] = tree[ind] + diff;
		if(s != e)
		{
			lazy[ind*2+1] += diff;
			lazy[ind*2+2] += diff;
		}
		//lazy[ind] = 0;
		return;
	}
	//if(s == e){ tree[ind] += diff; return;}
	ll mid = (s+e)/2;
	update(s, mid, qs, qe, diff, ind*2+1);
	update(mid+1, e, qs, qe, diff, ind*2+2);	
	tree[ind] = max(tree[ind*2+1], tree[ind*2+2]);
	
}

int main()
{
	ll n; cin>>n;
	vector<ll> arr;
	for(int i = 0; i < n; i++)
	{
		ll a; 
		cin>>a; arr.push_back(a);
	}
	//for(int i = 0; i <= 400005; i++) tree[i] = mini;
	build(0, n-1, 0, arr);
	int m; cin>>m;
	for(int i = 0; i < m; i++)
	{
		ll t;
		cin>>t;
		// a == 0 : update
		// a == 1 : query
		if(t == 0)
		{
			ll a, b;
			cin>>a>>b;
			cout<<query(0, n-1, 0, a, b)<<'\n';
		}else if(t == 1)
		{
			ll c,d,e;
			cin>>c>>d>>e;
			update(0, n-1,c,d,e,0); 
		}
		
	}/*
	for(int i = 0; i <= 40; i++)
	{
	    cout<<tree[i]<<" ";
	}*/
	
	
}
