#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200010;
const ll mod = 1e9+7;
int n,m;
vector <int> l[sz];
ll a[sz],b[sz],r[sz];
ll cnt[sz];
queue < int > q;
void build(int f,int t)
{
	l[f].push_back(t);
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			l[i].clear();
			scanf("%lld%lld",&a[i],&b[i]);
			a[i] %= mod;
			b[i] %= mod;
			r[i] = 0 , cnt[i] = b[i];
		}
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t;
			scanf("%d%d",&f,&t);
			build(t,f);
			r[f] ++;
		}
		for(int i = 1 ; i <= n ; i ++)
			if(!r[i])
				q.push(i);
		while(!q.empty())
		{
			int f = q.front();
			q.pop();
			for(int i = 0 ; i < l[f].size() ; i ++)
			{
				int t = l[f][i];
				r[t] --;
				cnt[t] += cnt[f];
				cnt[t] %= mod;
				if(!r[t])
				{
					q.push(t);
				}
			}
		}
		ll ans = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			ans += (a[i] * (cnt[i]- b[i]))%mod;
			ans %= mod;
		}
		while(ans < 0)
			ans += mod;
		printf("%lld\n",ans);
	}
	
	return 0;
}
/*
3 3
1 1
1 1
1 1
1 2
1 3
2 3
2 2
1 0
0 2
1 2
1 2
2 1
500000000 0
0 500000000
1 2
*/

