#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	string b;
	cin>>n>>k>>b;
    deque<int> v;
	for(int i  = 0; i < n; i++)
	{
		v.push_back(i);
	}
	for(int i = 0; i < b.size(); i++)
	{
		if(b[i] == 'A')
		{
		    int temp = v[0];
		    v.push_back(temp);
		    v.pop_front();
		}else if(b[i] == 'B')
		{
		    int temp1 = v[1];
		    v[1] = v[0];
		   v[0] = temp1;
		   v.push_back(temp1);
		   v.pop_front();
		}
	}
	cout<<v[k-1]<<" "<<v[k]<<" "<<v[k+1];
}
