#include<bits/stdc++.h>
using namespace std;
const int sz = 200010;
struct node
{
	int p,d;
	bool operator < (const node &a) const
	{
		return a.d < d;
	}
};
priority_queue <node> q;
bool use[sz];
int dist[sz];
int tim[sz];
int l[1010][1010];
int n;

int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&dist[i]) , q.push({i,dist[i]}) , tim[i] = 1;
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c) != EOF)
	{
		l[a+1][b+1] = c+1;
		l[b+1][a+1] = c+1;
	}
	while(!q.empty())
	{
		node f = q.top();
		q.pop();
		if(use[f.p])
			continue;
		use[f.p] = 1;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(l[f.p][i] && use[i] == 1)
			{
				int t = l[f.p][i];
				if(dist[t] > dist[f.p] + dist[i])
				{
					dist[t] = dist[f.p] + dist[i];
					tim[t] = tim[f.p] * tim[i];
					q.push({t,dist[t]});
				}
				else if(dist[t] == dist[f.p] + dist[i])
				{
					tim[t] += tim[f.p] * tim[i];
				}
			}
		}
	}
	printf("%d %d\n",dist[1],tim[1]);
	return 0;
}

