#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, s; cin>>n>>s;
	//int arr[n+2];
	deque<int> d;
	//cout<<"g";
	for(int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		d.push_back(a);
	}
	vector<int> v;
	int counter = 0;
	//if(d[0] == 0) counter+=1;
	/*
	for(int i = 1; i <= n - 1; i++)
	{
		cout<<"d";
   		if(d[i] == 0 && d[i-1] == 0)
   		{	
       		counter+=1;
			continue;
   		} else if(d[i] == 1 && d[i-1] == 0)
		{
			counter+=1;
			v.push_back(counter);
			counter = 0;
		}else if(d[i] == 0 && d[i-1] == 1)
		{
			counter+=1;
			continue;
		}
	}
	*/
	if(d.size() == 1 && d[0] == 0) { cout<<0; return 0;} 
	for(int i = 0; i <= n - 1; i++)
	{
		//cout<<"h";
		if(d[i] == 0)
		{
			counter+=1;
			if(i +1 <= n-1){ 
			while(d[i+1] != 1)
			{
				counter+=1;
				i++;
				if(i + 1 > n-1) break;
			}
			}
			v.push_back(counter);
			counter = 0;
			//cout<<"v.size(): "<<v.size()<<endl;
		}else if(d[i] == 1) continue;
	}
	//cout<<"k";
	//cout<<"size: "<<v.size();
	counter = 0;
	if(d[0] == 0) 
	{   counter+=v[0];
	    v.erase(v.begin());
	    //cout<<"counter2: "<<counter<<endl;
	    }
	if(d[n-1] == 0)
	{   
		//cout<<"l";
	    counter+=v[v.size()-1];
	    //cout<<"counter1: "<<counter<<endl;
	    v.pop_back();
	}
	//cout<<"g";
	//cout<<"counter: "<<counter<<endl;
	int g = v.size();
	//for(int i = 0; i < g; i++) cout<<v[i]<<endl;
	if(v.size() > 0){
    sort(v.begin(), v.end(), greater<int>()); }
    //v.reverse(v.begin(), v.end());
    int l = s-1;
    if(v.size() > 0){
		int p = v.size();
    for(int i = 0; i < l; i++)
    {
		if(i > p-1) break;
		//cout<<"counter: "<<counter<<endl;
        counter+=v[i];
    }
    }
    cout<<n-counter;
}

