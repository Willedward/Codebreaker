#include <bits/stdc++.h>

using namespace std;

int px[9] = {-1, -1, -1, 0, 0, 1, 1, 1};
int py[9] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main()
{
	int x, y, mx, my;
	cin>>x>>y>>mx>>my;
	char grid[1000][1000];
	int rock = 0;
	int vis[1000][1000];
	for(int i = 0; i <= y+2; i++)
	{
		for(int j = 0; j <= x+2; j++)
		{
			vis[i][j] = 0;
		}
	}
	for(int i = 1; i <= y; i++)
	{
		for(int j = 1; j <= x; j++)
		{
			cin>>grid[i][j];
			if(grid[i][j] == '*') 
			{
				//rock+=1;
				vis[i][j] = 1;					   
			 }
		}
	}
	queue<pair<int, pair<int,int>>> q; //dist pos
	my = y-my + 1;
	q.push({0, {my, mx}});
	//vis[my-1+y][mx] = 1;
	//int counter = 1;
	
	//int week = 1;
	//cout<<"rock: "<<rock<<endl;
	int maks=  1;
	
	//cout<<endl;
	while(!q.empty())
	{
		pair<int, pair<int, int>> p = q.front(); q.pop();
		//cout<<"i: "<<p.second.first<<" j: "<<p.second.second<<endl;
		for(int i = 0; i < 8; i++)
		{
			int a = p.second.first + px[i];
			int b = p.second.second + py[i];
			int dist = p.first;
		if(vis[a][b] != 1 && a >= 1 && a <= y && b >= 1 && b <= x)
		{
			q.push({dist+1, {a, b}});
			vis[a][b] = 1;
			maks = max(maks, dist+1);
		}
		}/*
		for(int i = 1; i <= y; i++)
		{
		    for(int j = 1; j <= x; j++)
		    {
		        cout<<vis[i][j]<<" ";
		    }
		    cout<<endl;
		}
		cout<<endl;*/
		//maks = max(maks, p.first);
		/*cout<<"maks: "<<maks<<endl;
		cout<<endl;
		cout<<endl;*/
		//q.pop();
	}
	cout<<maks;
}
