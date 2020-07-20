#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 2e6+7;
const int cnt = 4e5;
char ins[sz];
ll upt[sz],dwt[sz],lft[sz],rtt[sz];
int l;
int main()
{
    int T;
    scanf("%d",&T);
    while(T --)
    {
        scanf("%s",ins);
        int l = strlen(ins);
        ll x = 0 , y = 0;
        ll up = 0 , dw = 0,lf = 0, rt = 0;
        upt[0] = 1 , dwt[0] = 1 , lft[0] = 1 , rtt[0] = 1;
        for(int i = 0 ; i < l ; i ++)
        {
            if(ins[i] == 'W')
            {
                x ++;
                if(x > up)
                    up = x;
                upt[x+cnt] ++;
            }
            else if(ins[i] == 'S')
            {
                x --;
                if(x < dw)
                    dw = x;
                dwt[x+cnt] ++;
            }
            else if(ins[i] == 'A')
            {
                y --;
                if(y < lf)
                    lf = y;
                lft[y+cnt] ++;
            }
            else if(ins[i] == 'D')
            {
                y ++;
                if(y > rt)
                    rt = y;
                rtt[y+cnt] ++;
            }
        }
        ll r = up - dw + 1 , c = rt - lf + 1;
        ll ans = r * c;
        bool ws = 0 , ad = 0;
        for(int i = dw+cnt ; i <= up + cnt ; i ++)
        {
            if(dwt[i] == 1 || upt[i] == 1)
            {
                ws = 1;
                break;
            }
            dwt[i] = 0 , upt[i] = 0;
        }
        for(int i = lf+cnt ; i <= rt + cnt ; i ++)
        {
            if(lft[i] == 1 || rtt[i] == 1)
            {
                ad = 1;
                break;
            }
            lft[i] = 0 , rtt[i] = 0;
        }
        if(ws)
        {
            ans = min(ans,max(r-1,(ll)2)*c);
        }
        if(ad)
        {
            ans = min(ans,r*max(c-1,(ll)2));
        }
//        printf("%d %d %d %d\n",upt,dwt,lft,rtt);
        printf("%I64d\n",ans);
    }
    return 0;
}