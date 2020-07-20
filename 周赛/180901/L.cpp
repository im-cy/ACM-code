#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int size = 800100;
int n,m,k;
int hed[size],nxt[size];
ll dist[size][11];
bool use[size][11];
struct dc
{
    int t;
	ll d;
}l[size];
int tot = 1;
void Add_Link(int f, int t, ll d)
{
    l[tot].t = t;
    l[tot].d = d;
    nxt[tot] = hed[f];
    hed[f] = tot ++;
}
queue < int > q;
void init()
{
	while(!q.empty())
		q.pop();
	tot = 1;
	memset(l,0,sizeof(l));
	memset(hed,0,sizeof(hed));
	memset(nxt,0,sizeof(nxt));
	memset(use,0,sizeof(use));
	memset(dist,0,sizeof(dist));
}
void spfa(int s)
{
    for(int i = 0; i <= n; i ++)
        for(int j = 0; j <= k; j ++)
            dist[i][j] = 214748364111111111ll;
    dist[s][0] = 0;
    use[s][0] = 1; 
    q.push(s);
    q.push(0);
    while(!q.empty())
    {
        int f = q.front(); 
        q.pop();
        int tim = q.front();
        q.pop();
        use[f][tim] = 0;
        for(int i = hed[f]; i; i = nxt[i])
        {
            int t = l[i].t;
            if(dist[t][tim] > dist[f][tim] + l[i].d)
            {
                dist[t][tim] = dist[f][tim] + l[i].d;
                if(!use[t][tim])
                {
                    use[t][tim] = 1;
                    q.push(t);
                    q.push(tim);
                }
            }
            if(tim < k)
            {
                if(dist[t][tim+1] > dist[f][tim])
                {   
                    dist[t][tim+1] = dist[f][tim];
                    if(!use[t][tim+1])
                    {
                        use[t][tim+1] = 1;
                        q.push(t);
                        q.push(tim+1);
                    }
                }
            }
        }
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t --) 
    {
    	init();
    	scanf("%d%d%d",&n,&m,&k);
    	for(int i = 1; i <= m; i ++)
    	{
    	    int f,t;
			ll d;
    	    scanf("%d%d%lld",&f,&t,&d);
    	    Add_Link(f,t,d);
    	}
    	spfa(1);
    	cout << dist[n][k] << endl;
   	}
    return 0;
}
