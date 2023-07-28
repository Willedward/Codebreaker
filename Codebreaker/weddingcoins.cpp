//q5
#include <bits/stdc++.h>
using namespace std;

int main(){
    int coins[13] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000,50000, 100000, 500000, 1000000}; // all the denimination
    long long n;
    cin>>n;
    int p = 12; // pointer (address of coins[])
    long long counter = 0; // long long because the max is 10^18
    
    while (n>0){
        long long cur = n/coins[p];
        counter += cur;
        n = n - (coins[p]*cur);
        p--;
        
        //cout << cur << " " << counter<< endl;
    }
    //cout << endl;
    cout<<counter;
    

}
