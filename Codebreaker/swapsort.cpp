#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, q;
	cin>>n;
	int arr[n+1];
	int cnt = 0;
	for(int i = 1; i<=n; i++)
	{
		cin>>arr[i];
		if(arr[i] != i) cnt++;
	}
	cin>>q;
	int counter = 0;
	for(int i = 0; i < q; i++)
	{
		int a, b;
		cin>>a>>b;
		if(arr[a] == b) cnt--;
		else if(arr[a] == a) cnt++;
		if(arr[b] == a) cnt--;
		else if(arr[b] == b) cnt++;
		swap(arr[a], arr[b]);
		if(cnt == 0) counter+=1;
	}
	cout<<counter<<'\n';
	for(int i = 1; i<=n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
	
}
