#include <bits/stdc++.h>

using namespace std;

vector<int>tree(4*1000005);

int INF = 1e9;

void build(int low, int high, int index, vector<int> &v)
{
	if(low == high)
	{	
		tree[index] = v[low];
		return;
	}
	int mid = (high + low)/2;
	build(low, mid, index*2+1, v);
	build(mid+1, high, index*2+2, v);
	tree[index] = min(tree[index*2+1], tree[index*2+2]);
}

int query(int l, int r, int low, int high, int index)
{
	if(l <= low && r >= high)
	{
		return tree[index];
	}
	else if(l > high || r < low)
	{
		return INF;
	}
	int mid = (high + low)/2;
	int left = query(l, r, low, mid, index*2+1);
	int right = query(l, r, mid+1, high, index*2+2);
	return min(left, right);
}

int main()
{
	int n, k; cin>>n>>k;
	vector<int> v;
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		int a;cin>>a;
		v.push_back(a);
	}
	int minimum = INF;
	sort(v.begin(), v.end());
	vector<int>diff;
	for(int i = 0; i < n-1; i++)
	{
		int p1 = v[i];
		int p2 = v[i+1];
		int s = abs(p1-p2);
		diff.push_back(s);
		//cout<<"s: "<<s<<" ";
	}
	//cout<<endl;
	build(0, n-2, 0, diff);
	//for(int i = 0; i <= 7; i++) cout<<tree[i]<<" ";
	//cout<<endl;
	for(int i = 0; i < k; i++)
	{
	    //cout<<"v[i]: "<<v[i]<<" v[i+n-k]: "<<v[i+n-k-1]<<endl;
		int x = query(i, i+n-k-1, 0, n-2, 0);
		//cout<<x<<endl;
		int f = abs(v[i] - v[i+n-k-1]);
		//cout<<f<<endl;
		minimum = min(x+f, minimum);
		//cout<<"minimum: "<<minimum<<endl;
	}
	//cout<<"g"<<endl;
	cout<<minimum;
}
