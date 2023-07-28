#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    int n, k;cin>>n>>k;
    vector<vector<long long>> v(3);
    for(int i = 0; i < n; i++)
    {
        ll a;
        cin>>a;
        v[0].push_back(a);
    }
    for(int i = 0; i < n; i++)
    {
        long long b; cin>>b;
        v[1].push_back(b);
    }
    ll dp[2][n+5];
    dp[0][0] = v[0][0];
    dp[1][0] = v[1][0];
    for(int i = 1; i < n; i++)
    {
        dp[0][i] = max(dp[0][i-1] + v[0][i], dp[1][i-1] + v[0][i] - k);
        dp[1][i] = max(dp[0][i-1] + v[1][i] - k, dp[1][i-1] + v[1][i]);
        //cout<<dp[0][i]<<" "<<dp[1][i]<<endl;
        //cout<<"v[!check]"<<v[!check][i]-k<<" "<< v[check][i]<<endl;
    }
    cout<<max(dp[0][n-1], dp[1][n-1]);
    
}
 
