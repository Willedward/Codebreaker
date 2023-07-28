#include <bits/stdc++.h>

using namespace std;

int main()

{

	string s;	getline(cin, s);

	vector<char> v;

	int n = s.size();

	bool kena = false;

	for(int i = 0; i < n; i++)

	{

		if(s[i] == ' ') continue;

		else if((s[i] >= 'A' && s[i] <= 'Z' ) || (s[i] >= 'a' && s[i] <= 'z'))

		{

		    char temp = s[i];

		    if(s[i]<='Z') temp = s[i] - 'A' + 'a';

		    if(temp == 'a') kena = true;

		    if(kena){

			v.push_back(temp);

		    }

		    }

	}

	long long si = v.size();

	vector<vector<unsigned long long>> dp(30);

	for(int i = 0; i < 28; i++) dp[i].push_back(0);

	for(int i = 0; i < si; i++)

	{

	    unsigned long long k = v[i]-'a';

	    if(k == 0) dp[k].push_back(dp[k].back()+1);

	    else{

	    unsigned long long temp = dp[k-1].back() + dp[k].back();// k-1 = -1

	    dp[k].push_back(temp);

	    }

	}

	cout<<dp[25].back();

}
