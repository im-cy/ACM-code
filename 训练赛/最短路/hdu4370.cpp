#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int sz = 200010;
int C[301][301];
int dist[301];
bool use[301];
int n;
queue < int > q;
void spfa(int s)
{
	for(int i = 1 ; i <= n ; i ++)
		dist[i] = 214748364;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(i != s)
		{
			dist[i] = C[s][i];
			use[i] = 1;
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		use[f] = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			if(dist[i] > dist[f] + C[f][i])
			{
				dist[i] = dist[f] + C[f][i];
				if(!use[i])
				{
					use[i] = 1;
					q.push(i);
				}
			}
		}
	}
	return ;
}


int main()
{
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= n ; j ++)
			{
				scanf("%d",&C[i][j]);
				
				
			}
		}
		spfa(1);
		int ans1 = dist[1] , ans2 = dist[n];
		spfa(n);
		ans1 += dist[n];
		printf("%d\n",min(ans1,ans2));
	}
	return 0;
}

