#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, p;
	cin>>n>>p;
	int v[n+10];
	for(int i = 0; i < n; i++)
	{
		cin>>v[i];
	}
	int counter = 0;
	int temp = 0;
	int x = p;
	//cout<<x<<endl;
	for(int i = 0; i < n; i++)
	{
	    //cout<<"v[i]: "<<v[i]<<endl;
		if(x - v[i] >=0)
		{
			temp += 1;
			x-=v[i];
			//cout<<"x: "<<x<<endl;
		}else
		{
			while(x - v[i] < 0)
			{
				x+=v[i-temp];
				temp -= 1;
				//cout<<"temp: "<<temp<<" x: "<<x<<endl;
				//cout<<"v[i]: "<<v[i]<<endl;
			}
			temp+=1;
			x-=v[i];
			//cout<<"x: "<<x<<endl;
		}
		counter = max(counter, temp);
	    //cout<<"counter: "<<counter<<endl;
	    
	}
	cout<<counter;
}
