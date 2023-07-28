#include <bits/stdc++.h>

using namespace std;

int main()

{

	unsigned long long n;	cin>>n;

	long long c = 1;

	//cout<<"f";

	long long counter = 0;

	//cout<<"l";

	for(int i = 63; i >= 0; i--)

		{

			long long k = n / (1ULL<<i);

            if(k > 0){

			n -= (k*(1ULL<<i));

			counter+=k;

            }

		}

	cout<<counter;
}
