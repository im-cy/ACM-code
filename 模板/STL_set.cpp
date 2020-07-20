#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#define ll long long
using namespace std;
struct gtnd
{
    ll id;
    ll p;
    bool operator <(const gtnd &a)const
    {
        return p < a.p;
    }
};
map < ll , ll > m;
set < gtnd > s;
set < gtnd > :: iterator f1,f2,temp;
int n;
int main()
{
    scanf("%d",&n);
    gtnd sta;
    sta.id = 1 , sta.p = 1000000000;
    m[sta.p] = 1;
    s.insert(sta);
    for(int i = 1 ; i <= n ; i ++)
    {
        gtnd nxt;
        scanf("%lld%lld",&nxt.id,&nxt.p);
        printf("%lld ",nxt.id);
        if(m[nxt.p])
        {
            printf("%lld\n",m[nxt.p]);
            m[nxt.p] = min(m[nxt.p],nxt.id);
            continue;
        }
        else
            m[nxt.p] = nxt.id;

        f1 = s.lower_bound(nxt);
        f2 = f1;
        f2 --;
        ll id_f1 = m[(*f1).p] , id_f2 = m[(*f2).p];
        ll a_f1 = abs((*f1).p - nxt.p) , a_f2 = abs((*f2).p - nxt.p);
        if(f2 == s.end())
            printf("%lld\n",id_f1);
        else if(f1 == s.end())
            printf("%lld\n",id_f2);
        else if(a_f1 > a_f2)
            printf("%lld\n",id_f2);
        else if(a_f1 < a_f2)
            printf("%lld\n",id_f1);
        else
        {
            if(id_f1 < id_f2)
                printf("%lld\n",id_f1);
            else
                printf("%lld\n",id_f2);
        }
        s.insert(nxt);
    }
    return 0;
}
