#include<bits/stdc++.h>
using namespace std;
const int sz = 2010;
int n,m,S,T,K;
int tot = 1;
struct edge
{
	int t,d;
}l[sz];
int hed[sz],nxt[sz],dist[sz][sz];
bool use[sz][sz];
struct node
{
	int p,k;
};
queue < node > q;
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
void spfa(int s)
{
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= K ; j ++)
			dist[i][j] = 214748364;
	dist[s][0] = 0;
	node st;
	st.p = s;
	st.k = 0;
	use[s][0] = 1;
	q.push(st);
	while(!q.empty())
	{
		node f = q.front();
		q.pop();
		use[f.p][f.k] = 0;
		for(int i = hed[f.p] ; i ; i = nxt[i])
		{
			int t = l[i].t;
			if(dist[t][f.k] > dist[f.p][f.k] + l[i].d)
			{
				dist[t][f.k] = dist[f.p][f.k] + l[i].d;
				if(!use[t][f.k])
				{
					use[t][f.k] = 1;
					node nxtf;
					nxtf.p = t;
					nxtf.k = f.k;
					q.push(nxtf);
				}
			}
			if(f.k < K)
			{
				if(dist[t][f.k+1] > dist[f.p][f.k])
				{
					dist[t][f.k+1] = dist[f.p][f.k];
					if(!use[t][f.k+1])
					{
						use[t][f.k+1] = 1;
						node nxtf;
						nxtf.p = t;
						nxtf.k = f.k + 1;
						q.push(nxtf);
						
					}
				}
				
				
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&n,&m,&S,&T,&K);
	for(int i = 1 ; i <= m ; i ++)
	{
		int f,t,d;
		scanf("%d%d%d",&f,&t,&d);
		build(f,t,d);
		build(t,f,d);
	}
	if(K >= m)
	{
		puts("0");
		return 0;
	}
	spfa(S);
	printf("%d\n",dist[T][K]);
	return 0;
}
/*
3 2 1 3 3
1 2 1
2 3 2
*/
