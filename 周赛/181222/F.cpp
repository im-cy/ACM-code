#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int sz = 12010;
struct point
{
	int x,y;
}S,T;
queue < point > q;
char in[sz][sz];
int dist[sz][sz];
bool use[sz][sz];
int r,c;
int main()
{
	int _;
	scanf("%d",&_);
	while(_ --)
	{
		scanf("%d%d",&r,&c);
		getchar();
		for(int i = 0 ; i < 4 * r + 3 ; i ++)
			gets(in[i]);
		r = 4 * r + 3;
		c = 6 * c + 3;
		for(int i = 0 ; i < r ; i ++)
		{
			for(int j = 0 ; j < c ; j ++)
			{
				dist[i][j] = 214748364;
				if(in[i][j] == 'S')
					S.x = i , S.y = j;
				if(in[i][j] == 'T')
					T.x = i , T.y = j;
			}
		}
		q.push(S);
		use[S.x][S.y] = 1;
		dist[S.x][S.y] = 0;
		while(!q.empty())
		{
			point f = q.front();
			q.pop();
			point edge;
			edge.x = f.x - 1;
			edge.y = f.y - 3;
			if(in[edge.x][edge.y] == ' ')
			{
				point nxt;
				nxt.x = edge.x - 1;
				nxt.y = edge.y - 3;
				dist[nxt.x][nxt.y] = min(dist[f.x][f.y]+1,dist[nxt.x][nxt.y]);
				if(!use[nxt.x][nxt.y])
				{
					use[nxt.x][nxt.y] = 1;
					q.push(nxt);
				}
			}
			edge.x = f.x + 1;
			edge.y = f.y - 3;
			if(in[edge.x][edge.y] == ' ')
			{
				point nxt;
				nxt.x = edge.x + 1;
				nxt.y = edge.y - 3;
				dist[nxt.x][nxt.y] = min(dist[f.x][f.y]+1,dist[nxt.x][nxt.y]);
				if(!use[nxt.x][nxt.y])
				{
					use[nxt.x][nxt.y] = 1;
					q.push(nxt);
				}
			}
			edge.x = f.x + 1;
			edge.y = f.y + 3;
			if(in[edge.x][edge.y] == ' ')
			{
				point nxt;
				nxt.x = edge.x + 1;
				nxt.y = edge.y + 3;
				dist[nxt.x][nxt.y] = min(dist[f.x][f.y]+1,dist[nxt.x][nxt.y]);
				if(!use[nxt.x][nxt.y])
				{
					use[nxt.x][nxt.y] = 1;
					q.push(nxt);
				}
			}
			edge.x = f.x - 1;
			edge.y = f.y + 3;
			if(in[edge.x][edge.y] == ' ')
			{
				point nxt;
				nxt.x = edge.x - 1;
				nxt.y = edge.y + 3;
				dist[nxt.x][nxt.y] = min(dist[f.x][f.y]+1,dist[nxt.x][nxt.y]);
				if(!use[nxt.x][nxt.y])
				{
					use[nxt.x][nxt.y] = 1;
					q.push(nxt);
				}
			}
			edge.x = f.x - 2;
			edge.y = f.y;
			if(in[edge.x][edge.y] == ' ')
			{
				point nxt;
				nxt.x = edge.x - 2;
				nxt.y = edge.y;
				dist[nxt.x][nxt.y] = min(dist[f.x][f.y]+1,dist[nxt.x][nxt.y]);
				if(!use[nxt.x][nxt.y])
				{
					use[nxt.x][nxt.y] = 1;
					q.push(nxt);
				}
			}
			edge.x = f.x + 2;
			edge.y = f.y;
			if(in[edge.x][edge.y] == ' ')
			{
				point nxt;
				nxt.x = edge.x + 2;
				nxt.y = edge.y;
				dist[nxt.x][nxt.y] = min(dist[f.x][f.y]+1,dist[nxt.x][nxt.y]);
				if(!use[nxt.x][nxt.y])
				{
					use[nxt.x][nxt.y] = 1;
					q.push(nxt);
				}
			}
		}
		if(dist[T.x][T.y] == 214748364)
		{
			puts("-1");
		}
		else
		{
			printf("%d\n",dist[T.x][T.y]+1);
		}
		for(int i = 0 ; i < r ; i ++)
			for(int j = 0 ; j < c ; j ++)
				use[i][j] = 0;
	}
	return 0;
}

