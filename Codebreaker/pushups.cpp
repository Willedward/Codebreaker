#include <bits/stdc++.h>
using namespace std;

vector<int> a, segtree;
const int INF = 1e6;

int build(int low, int high, int pos)
{
    if(low == high)
    {
        segtree[pos] = a[low];
        return segtree[pos];
    }
    int mid = (low + high)/2;
    return segtree[pos] = max(build(low, mid, pos*2), build(mid+1, high, pos*2+1));
}

int query(int ql, int qh, int l, int h, int pos)
{
    if(ql > h || qh < l)
    {
        return 0;
    }
    if(ql <= l && qh >= h)
    {
        return segtree[pos];
    }
    int mid = (l + h)/2;
    return max(query(ql, qh, l, mid, pos*2), query(ql, qh, mid+1, h, pos*2 +1));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    a = vector<int> (INF + 2, 0);
    segtree = vector<int> (4*INF + 2);
    int t;
    cin>>t;
    for(int i = 1; i <= INF; i++)
    {
        for(int j = i; j <=INF; j+=i)
        {
            a[j] += i;
        }
    }
    build(1, INF, 1);
    
    for(int i = 0; i < t; i++)
    {
        int n;
        cin>>n;
        cout<<query(1, n, 1, INF, 1)<<'\n';
    } 
}








