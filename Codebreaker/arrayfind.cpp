#include <bits/stdc++.h>

using namespace std;

int l;

int bss(int arr[], int val)
{
	int right = l;
	int left = 1;
	int index;
	while(left <= right)
	{
		int mid = left + (right - left) / 2;
		if(arr[mid] <= val)
		{
			left = mid + 1;
		}else if(arr[mid] > val)
		{
			right = mid - 1;
			index = mid;
			//cout<<"mid: "<<mid<<endl;
		}
	}
	if(val > arr[index])
	{
		index = l+1;
	}
	return index;
}

int bsl(int arr[], int val)
{
	int right = l;
	int left = 1, index;
	while(left <= right)
	{
		int mid = left + (right - left)/2;
		if(arr[mid] >= val)
		{
			right = mid - 1;
		}else
		{
			left = mid + 1;
			index = mid;
			//cout<<"mid: "<<mid<<endl;
		}
	}
	if(val < arr[index])
	{
		index = 0;
	}
	return index;
}
int arr[1000001];

int main()
{
	int q;
	cin>>l;
	//int f[1000001];
	vector<int> v;
	for(int i = 1; i <= l; i++)
	{
		cin>>arr[i];
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	cin>>q;
	for(int i = 0; i < q; i++)
	{
		int great = 0, small = 0;
		int a;
		cin>>a;
		small = lower_bound(v.begin(), v.end(), a) - v.begin();
		great = (lower_bound(v.begin(), v.end(), a+1))-v.begin();
		great = l - great;
		cout<<"Smaller: "<<small<<", Greater: "<<great<<'\n';
	}
	
}
