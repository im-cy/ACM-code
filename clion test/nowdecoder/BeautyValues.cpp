#include<bits/stdc++.h>
using namespace std;
const int sz = 1100;
int ans[sz][sz];
int tmp[sz][sz];
int main()
{
    int m;
    scanf("%d",&m);
    ans[1][1] = 1;
    ans[1][2] = 1;
    ans[2][1] = 1;
    ans[2][2] = -1;
    for(int k = 4 ; k <= m ; k <<= 1)
    {
        for(int i = 1 ; i <= k/2 ; i ++)
        {
            for(int j = 1 ; j <= k/2 ; j ++)
            {
                tmp[i][j] = ans[i][j];
                ans[i][j] = 0;
            }
        }
        for(int i = 1 ; i <= k/2 ; i ++ )
        {
            for(int j = 1 ; j <= k/2 ; j ++)
            {
                ans[i*2-1][j*2-1] = tmp[i][j];
                ans[i*2][j*2-1] = tmp[i][j];
                ans[i*2-1][j*2] = tmp[i][j];
                ans[i*2][j*2] = -tmp[i][j];
            }
        }
    }
    for(int i = 1 ; i <= m ; i ++)
    {
        for(int j = 1 ; j <= m ; j ++)
        {
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
    return 0;
}
