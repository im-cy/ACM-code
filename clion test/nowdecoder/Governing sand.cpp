#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200010;
struct Tree
{
    ll h,c,p;
}tree[sz];
bool cmp(Tree a,Tree b)
{
    if(a.h == b.h)
       return a.c < b.c;
    return a.h < b.h;
}
ll mp[301],sum[sz],sump[sz];
vector < int > v;
int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        v.clear();
        memset(mp,0,sizeof(mp));
        memset(sum,0,sizeof(sum));
        memset(sump,0,sizeof(sump));
        memset(tree,0,sizeof(tree));
        for(int i = 1 ; i <= n ; i ++)
            scanf("%lld%lld%lld",&tree[i].h,&tree[i].c,&tree[i].p);
        sort(tree+1,tree+n+1,cmp);
        for(int i = n ; i >= 1 ; i --)
            sum[i] = sum[i+1] + tree[i].c * tree[i].p , sump[i] = sump[i+1] + tree[i].p;
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(int i = 1 ; i <= n ; i ++)
            if(tree[i].h != tree[i-1].h)
                v.push_back(i);
        v.push_back(n+1);

        for(int i = 0 ; i < v.size()-1 ; i ++)
        {
            ll tmp = sum[v[i+1]] , cut = sump[v[i+1]];
            ll len = sump[v[i]] - cut;
            ll left = sump[1] - cut;
        //    printf("i %d v[i] %d\n",i,v[i]);
        //    printf("tmp %lld\n",tmp);
            if(len * 2 <= left)
            {
                ll need = left - len * 2 + 1;
        //        printf("need %lld\n",need);
                for(ll j = 1 ; j <= 200 ; j ++)
                {
                    ll temp = mp[j];
                    if(!temp)
                        continue;
                    if(temp >= need)
                    {
                        tmp += j * need;
                        break;
                    }
                    else
                    {
                        tmp += j * temp;
                        need -= temp;
                    }
                }
            }
            for(int j = v[i] ; j < v[i+1] ; j ++)
     //           if(tree[j].c != tree[j-1].c)
                    mp[tree[j].c] += tree[j].p;
            ans = min(ans,tmp);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
