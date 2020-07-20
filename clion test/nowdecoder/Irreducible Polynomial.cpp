#include<bits/stdc++.h>
using namespace std;
int fac[20100],cnt = 0;
int num[31];
int n;
void factor(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            fac[++cnt]=i;
            while(n%i==0)
            {
                n/=i;
            }
        }
    }
    if(n!=1)
        fac[++cnt]=n;
}
bool check(int p)
{
    if(num[n+1] % p == 0)
        return false;
    for(int i = 1 ; i <= n ; i ++)
        if(num[i] % p)
            return false;
    p = p * p;
    if(num[1]%p == 0)
        return false;
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T --)
    {
        memset(fac,0,sizeof(fac));
        cnt = 0;
        scanf("%d",&n);
        for(int i = 1 ; i <= n + 1 ; i ++)
            scanf("%d",&num[i]);
        for(int i = 2 ; i <= n + 1 ; i ++)
        {
            if(!num[i])
                continue;
            factor(num[i]);

        }
        sort(fac+1,fac+cnt+1);
        int m = unique(fac+1,fac+cnt+1) - (fac+1);
        bool ans = 1;
        for(int i = 1 ; i <= m ; i ++)
        {
            if(!num[i])
                continue;
            if(check(fac[i]))
                ans = 0;
        }
        if(ans)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
