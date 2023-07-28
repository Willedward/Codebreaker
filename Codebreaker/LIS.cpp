#include <bits/stdc++.h>

using namespace std;

int bsta(vector<int> &tail, int l, int r, int key)
{
	int mid = l + (r-l)/2;
	if(r >= key)
	{
		r = mid
	}else l = mid;
	return mid;
}


int main()
{
	int n
	cin>>n;
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		int a;cin>>a;
		v.push_back(a);
	}
	vector<int> tail;
	int l = v.size();
	tail = vector<int>(l, 0);
	tail[0] = v[0];
	int length = 1;
	for(int i = 1; i < n; i++)
	{
		if(v[i] < tail[0]) tail[0] = v[i];
		else if(v[i] > tail[length-1])
		{
			tail[length++] = v[i];
		}
		else
		{
			tail[bsta(tail, 0, length-1, v[i])] = v[i];
		}
	}
	cout<<length;
	
}
