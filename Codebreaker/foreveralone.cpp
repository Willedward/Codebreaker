#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m; cin>>n>>m;
	set<int> s;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin>>a>>b;
		//cout<<"b";
		if(a != b)
		{
			s.insert(a);
			s.insert(b);
		}
	}
	int size = s.size();
	int sum = n-size;
	cout<<sum;
}
