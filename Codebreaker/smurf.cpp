#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	int v[n];
	for(int i = 1; i <= n; i++)
	{
		cin>>arr[i];
	}
	bool check = false;
	if(n % 2 == 1)
	{
		check = true;
	}
	int counter = 0;
	for(int i = n; i >= 1; i-=2)
	{
		v[counter] = arr[i];
		//cout<<"arr[i]1: "<<arr[i]<<endl;
		counter++;
	}
	int temp;
	if(check) {temp = 2;}
	else {temp = 1;}
	for(int i = temp; i <=n-1; i+=2)
	{
		v[counter] = arr[i];
		//cout<<"arr[i]2: "<<arr[i]<<endl;
		counter++;
	} 
	for(int i = 0; i < n; i++)
	{
		cout<<v[i]<<" ";
	}
}
