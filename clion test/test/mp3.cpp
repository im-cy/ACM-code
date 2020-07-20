#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 800100;
ll n,I;
ll num[sz];
ll tmp[sz];
ll sum[sz];
ll T[sz];
int main()
{
    scanf("%I64d%I64d",&n,&I);

 //   m = R - L + 1;
    for(int i = 1 ; i <= n ; i ++)
    {
        scanf("%I64d",&num[i]);
        tmp[i] = num[i];
    }
    sort(tmp+1,tmp+n+1);
    ll tot = unique(tmp+1,tmp+n+1) - (tmp+1);
    for(int i = 1 ; i <= n ; i ++)
    {
        num[i] = lower_bound(tmp+1,tmp+n+1,num[i]) - (tmp);
        T[num[i]] ++;
    }
    sort(num+1,num+n+1);
    tot = unique(num+1,num+n+1) - (num+1);
    I *= 8;
    ll bit = I / n;
    ll m = 1;
    for(int i = 1 ; i <= bit ; i ++)
    {
        if(m >= tot)
            break;
        m *= 2;
    }
    ll ans = 2147486341111111ll;
    for(int i = 1 ; i <= tot ; i ++)
    {
        sum[i] = sum[i-1] + T[num[i]];
    }
    for(int i = 1 ; i <= tot ; i ++)
    {
        int R = min(i + m - 1,tot);
        ans = min(ans,n - (sum[R]-sum[i-1]));
    }
    printf("%I64d\n",ans);
    return 0;
}
