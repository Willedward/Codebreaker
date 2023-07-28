#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll tree[4*100000+4];

void build(ll low, ll high, ll index, vector<long long> &v)

{

    //cout<<"j";

if(low == high)

{

tree[index] = v[low];

return;

}

ll mid = low + (high-low)/2;

build(low, mid, index*2+1, v);

build(mid+1, high, index*2+2, v);

}

long long IT_MAX = 1e10;

long long query(long long l, ll r, ll low, ll high, ll index, vector<long long> &v)

{

if(low >= l && high <= r)

{

return tree[index];

}

else if(l > high || r < low)

{

return IT_MAX;

}

ll mid = (high + low)/2;

long long left = query(l, r, low, mid, index*2+1, v);
//long long right = 1e10;
ll right = query(l, r, mid+1, high, index*2+2, v);
tree[index] = min(left, right);
return min(left, right);

}


int main()

{

int n, k; cin>>n>>k;

vector<long long>v;

v.push_back(0);

vector<long long> dp(n+2);

for(int i = 0; i < n; i++)

{

long long a;cin>>a;

v.push_back(a);

//cout<<"k"<<i<<endl;

}

//cout<<"t";

//cout<<"k";

build(1, n, 0, v);

dp[0] = 0;

//cout<<v[0];

//int counter = 0;
//update(1, n, 0);
for(int i = 1; i <= n; i++)

{

long long temp = query(max(1, i-k), i, 1, n, 0, v);
cout<<"i-k: "<<i-k<<endl;
cout<<"max: "<<max(1, i-k)<<endl;
//cout<<"i: "<<i<<endl;
cout<<"query: "<<query(max(1, i- k), i, 1, n, 0, v)<<endl;
dp[i] = max(v[i], temp);

//cout<<temp<<endl;

cout<<"dp[i]: "<<dp[i]<<"i: "<<i<<endl;

}

long long small = 1e10;

for(int i = n; i >= n-k+1; i--) small = min(small, dp[i]);
/*
for(int i  = 0; i < 4*n; i++)
{
    cout<<tree[i]<<" ";
}
*/
cout<<small;
//cout<<query(1, 2, 1, n, 0, v);
}
