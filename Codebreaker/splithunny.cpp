#include <bits/stdc++.h>

using namespace std;
char arr[502][500];
int visited[502][500];

void dfs(int i, int j)
{
    visited[i][j] = 1;
    if(arr[i-1][j] == 'H' && visited[i-1][j] != 1) dfs(i-1, j);
    if(arr[i+1][j] == 'H' && visited[i+1][j] != 1) dfs(i+1, j);
    if(arr[i][j-1] == 'H' && visited[i][j-1] != 1) dfs(i, j-1);
    if(arr[i][j+1] == 'H' && visited[i][j+1] != 1) dfs(i, j+1);
}

int main()
{
	int r, c;
	cin>>r>>c;
	int counter = 0;
	for(int i = 1; i <=r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			char a;
			cin>>a;
			arr[i][j] = a;
		}
	}
	for(int i = 1; i <=r; i++)
	{
		for(int j = 1; j <= c; j++)
		{
			visited[i][j] = 0;
		}
	}
	
	for(int i = 1; i <= r; i++)
	{
	    for(int j =0 ; j <= c; j++)
	    {
	        if(arr[i][j] == 'H' && visited[i][j] == 0)
	        {
	            counter+=1;
	            dfs(i, j);
	        }
	    }
	}
	
	cout<<"Oh, bother. There are "<<counter<<" pools of hunny.";
}
