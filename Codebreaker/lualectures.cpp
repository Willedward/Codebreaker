#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    vector<pair<pi, int>> store;
    queue<pair<int, int>> q;
    priority_queue <pi, vector<pi>, greater<pi>> pq;
    int arr[n+2];
    for(int i = 1; i <= n; i++)
    {
        int start, end;cin>>start>>end;
        store.push_back({{start,end}, i});
    }
    sort(store.begin(), store.end());
    v.push_back({0, 1});
    pq.push({0, 1});
    for(auto f:store)
    {
        int t, t1, t2;
        t = f.first.first; t1 = f.first.second; t2 = f.second;
        int l = pq.top().first, l1 = pq.top().second;
        if(l < t)
        {
            //cout<<"--------- l < t --------"<<endl;
            v[l1-1].first = t1;
			int j = pq.top().second;
            arr[t2] = j;
            //cout<<"arr[t2]: "<<arr[t2]<<endl;
            pq.push({t1, j});
            pq.pop();
        }
        else
        {
            //cout<<"--------- l > t --------"<<endl;
            int s = v.size();
            v.push_back({t1, s+1});
            arr[t2] = s+1;
            //cout<<"arr[t2]: "<<arr[t2]<<endl;
            pq.push({t1, s+1});
        }
    }
    cout<<v.size()<<'\n';
    for(int i = 1; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
