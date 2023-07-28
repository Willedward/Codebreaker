#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<pair<int, int>> v;
	for(int i = 0; i < n; i++)
	{
		int a, b;
		cin>>b>>a;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	int counter = 0;
	int check = 0;
	for(auto f:v)
	{
		int a, b;
		a = f.first;
		b = f.second;
		if(b >= check)
		{
			check = a;
			counter+=1;
		}
	}
	cout<<counter;
	
}
