#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n, l ,t;
	cin>>n>>l>>t;
    vector <int> v;
	for(int i = 1; i <= n; i++)
	{
		int a; cin>>a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	int dist[n+4];
	dist[0] = v[0];
	for(int i = 1; i < n; i++)
	{
	    dist[i] = v[i] - v[i-1];
	}
	dist[n] = l-v[n-1];
	int counter = 0;
	int track = 0;
	int full = 0;
	for(int i = 0; i <= n; i++)
	{
	    if(dist[i] > t) 
	    {
	        cout<<"-1"; return 0;
	    }
	    full += dist[i];
	    if(full > t)
	    {
	        //cout<<v[i-1]<<endl;
	        counter+=1;
	        full = 0;
	        full+=dist[i];
	    }
	}
	cout<<counter;
	
}
