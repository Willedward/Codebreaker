#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c, r;
	cin>>r>>c;
	vector<vector<long long>> v(26);
	v[1].push_back(1);
	v[2].push_back(1);
	v[2].push_back(1);
	for(int i = 3; i <= 25; i++)
	{
		long long counter = 0;
		counter = 0;
		long long j = 0;
		v[i].push_back(1);
		//cout<<v[i][0]<<" ";
		while(j < i-2)
		{
			long long k = v[i-1][j] + v[i-1][j+1];
			//cout<<"v[i-1][j]: "<<v[i-1][j]<<" v[i-1][j+1]: "<<v[i-1][j+1]<<endl;
			//cout<<"j: "<<j<<endl;
			v[i].push_back(k);
			//cout<<v[i][j+1]<<" ";
            j++;
		}
		v[i].push_back(1);
		//cout<<v[i][i]<<" ";
		//cout<<endl;
	}
	cout<<v[r][c-1]<<endl;
	/*
	for(int i = 1; i <= 25; i++)
	{
	    for(int j = 0; j < v[i].size(); j++)
	    {
	        cout<<v[i][j]<<" ";
	    }
	    cout<<endl;
	    
	}
	*/
}
