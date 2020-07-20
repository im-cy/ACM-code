#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int sz = 20001;
queue < int > q;
int n,m;
int dist[sz];
struct edge
{
    int t,d;
};
vector < edge > l[sz];
void build(int f,int t,int d)
{
	if(d >= 0)
		l[f].push_back({t,d}) , l[t].push_back({f,d});
	else
		l[f].push_back({t,d});
}
bool use[sz];
int tim[sz];
bool spfa(int s)
{
    for(int i = 1 ; i <= n ; i ++)
        dist[i] = 2147483641;
    dist[s] = 0;
    use[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        use[f] = 0;
        for(int i = 0 ; i < l[f].size() ; i ++)
        {
            int t = l[f][i].t;
            int d = l[f][i].d;
            if(dist[t] > dist[f] + d)
            {
                dist[t] = dist[f] + d;
                tim[t] = tim[f] + 1;
                if(tim[t] > n)
                    return false;
                if(!use[t])
                {
                	use[t] = 1;
                    q.push(t);
                }
            }
        }
    }
    return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		scanf("%d%d",&n,&m);
		while(!q.empty())
			q.pop();
		for(int i = 1 ; i <= n + 5 ; i ++)
			l[i].clear() , use[i] = 0 , tim[i] = 0;
		for(int i = 1 ; i <= m ; i ++)
		{
			int f,t,d;
			scanf("%d%d%d",&f,&t,&d);
			build(f,t,d);
		}
		bool ans = spfa(1);
		if(!ans)
			puts("YE5");
		else
			puts("N0");
	}
    return 0;
}
