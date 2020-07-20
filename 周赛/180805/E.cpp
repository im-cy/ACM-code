#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
bool Prime[500];
int jie[500][90];
__int64 zu[500][500];
int Primer[500],num;
void GetPrime()
{
    for(int i = 2; i <= 431; ++i)
        Prime[i] = true;
    for(int i = 2; i <= 431; ++i)
    {
        if(Prime[i])
        {
            for(int j = i+i; j <= 431; j+=i)
                Prime[j] = false;
        }
    }
    num = 0;
    for(int i = 0; i <= 431; ++i)
        if(Prime[i])
            Primer[num++] = i;
}
void solve()
{
    for(int i = 0;i < num; ++i)
        for(int j = 2; j <= 431; ++j)
            jie[j][i] = j/Primer[i] + jie[j/Primer[i]][i];
    for(int i = 2; i <= 431; ++i)
    {
        for(int j = 1; j < i; ++j)
        {
            zu[i][j] = 1;
            for(int k = 0; k < num && jie[i][k]; ++k)
            {
                int side = jie[i][k] - jie[j][k] - jie[i-j][k];
		        if(side)
                    zu[i][j] *= (side+1);
            }
        }
    }
}
int main()
{
    GetPrime();
    solve();
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        if(m==0 || m==n)
            printf("1\n");
        else
            printf("%I64d\n",zu[n][m]);
    }
 
    return 0;
}

