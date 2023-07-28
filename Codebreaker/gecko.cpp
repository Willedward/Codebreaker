#include <bits/stdc++.h>

using namespace std;

int main()

{

    int w, h;

    cin>>h>>w;

    int sum[h+10][w+10];

    int value[h+w][w+h];

    for(int i = 1; i <= h; i++)

    {

        for(int j = 1; j<=w; j++)

        {

            cin>>value[i][j];

        }

    }

    for(int i = 0; i<= h+1; i++)

    {

        for(int j = 0; j<=w+1; j++)

        {

            sum[i][j] = 0;

        }

    }

    for(int i = 1; i <= h; i++)

    {

        for(int j = 1; j <= w; j++)

        {

            int temp = max(sum[i-1][j-1], sum[i-1][j]);

            sum[i][j] = max(temp, sum[i-1][j+1]) + value[i][j];

            //cout<<"sum[i][j]: "<<sum[i][j]<<endl;

        }

    }

    int maks = 0;

    for(int j = 1; j<=w; j++)

    {

        //cout<<"sum[h][j]: "<<sum[h][j]<<endl;

        maks = max(maks, sum[h][j]);

    }

    cout<<maks;

}
