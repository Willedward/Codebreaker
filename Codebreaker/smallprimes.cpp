#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<long long> v;

ll cur;

void fill(){

	v.push_back(1ll);	cur = 2ll;

	ll curl;

	while (cur <= 1e18){

		v.push_back(cur);

		cur*=2ll;

	}

	

	v.push_back(3ll);

	curl = v.size();

	for(ll i = 0; i < curl; i++){

        cur = v[i];

        while (cur <= 1e18){

    		v.push_back(cur);

    		cur*=3ll;

        }

	}

	

	v.push_back(5ll);

	curl = v.size();

	for(ll i = 0; i < curl; i++){

        cur = v[i];

        while (cur <= 1e18){

    		v.push_back(cur);

    		cur*=5ll;

        }

	}

	

	v.push_back(7ll);

	curl = v.size();

	for(ll i = 0; i < curl; i++){

        cur = v[i];

        while (cur <= 1e18){

    		v.push_back(cur);

    		cur*=7ll;

        }

	}

}

int main()

{

	ll n; cin>>n;

	//cout << "hi";

	fill();

	//cout << v.size();

	set <ll> st(v.begin(), v.end());

	vector <ll> arr(st.begin(), st.end());

	sort(arr.begin(), arr.end());

	/*

	for(int i = 0; i < v.size(); i++)

	{

		cout<<v[i]<<" ";

	}*/

	for(ll i = 0; i < n; i++)

	{

	    long long a, b; cin>>a>>b;

	    ll k = lower_bound(arr.begin(), arr.end(), a)-arr.begin();

	    long long f = upper_bound(arr.begin(), arr.end(), b)-arr.begin();

	    ll maks = 0;

	    maks = f-k;

	    //if(arr[k] != a) maks +=1;

	    cout<<maks<<'\n';

	    

	}

	

	

}
