#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int counter = 0;
    int maks_def = v[0].second;
    if(v[0].first == v[1].first && v[0].second <= v[1].second) counter+=1;
    for(int i = 1; i <  n; i++)
    {
        if(v[i].second <= maks_def)
        {
            counter += 1;
        }
        if(v[i].second > maks_def) maks_def = v[i].second;
    }
    cout<<n-counter;
}
