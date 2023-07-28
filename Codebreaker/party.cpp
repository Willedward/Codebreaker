#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m; cin>>n>>m;
	vector<vector<int>> v(n+2);
	for(int i = 0; i< m; i++)
	{
		int a,b; cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int>path;
	int visited[502];
	for(int i = 0; i < 502; i++) visited[i] = 0;
	path.push_back(1);
	visited[1] = 1;
	int count = 0;
	for(int i = 0; i < v[1].size(); i++)
	{
	    int s = v[1][i];
	    if(visited[s] != 1){ count++;
	    visited[s]+=1;
	    }
	    for(int j = 0; j < v[s].size(); j++)
	    {
	        int f = v[s][j];
	        if(visited[f] != 1)
	        {
	            count++;
	            visited[f] = 1;
	        }
	    }
	}
	cout<<count;
}
