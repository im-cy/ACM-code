#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int n,m,p;
struct point
{
	int x,y,z,d;
}st,ed;
queue < point > q;
bool use[31][31][31];
char in[31][31][31];
int step[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int bfs()
{
	use[st.x][st.y][st.z] = 1;
	st.d = 0;
	q.push(st);
	while(!q.empty())
	{
		point f = q.front();
		q.pop();
		if(f.x == ed.x && f.y == ed.y && f.z == ed.z)
			return f.d;
		for(int i = 0 ; i < 6 ; i ++)
		{
			point nxt;
			nxt.x = f.x + step[i][0];
			nxt.y = f.y + step[i][1];
			nxt.z = f.z + step[i][2];
			nxt.d = f.d + 1;
			if(nxt.x >= 1 && nxt.x <= n && nxt.y >= 1 && nxt.y <= m && nxt.z >= 1 && nxt.z <= p && !use[nxt.x][nxt.y][nxt.z] && in[nxt.x][nxt.y][nxt.z] != '#')
			{
				use[nxt.x][nxt.y][nxt.z] = 1;
				q.push(nxt);
			}
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d%d%d",&n,&m,&p) && n && m && p)
	{
		memset(use,0,sizeof(use));
		while(!q.empty())
			q.pop();
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
			{
				for(int k = 1 ; k <= p ; k ++)
				{
					char ins = getchar();
					while(ins != 'S' && ins != 'E' && ins != '.' && ins != '#')
						ins = getchar();
					in[i][j][k] = ins;
					if(ins == 'S')
						st.x = i , st.y = j , st.z = k;
					if(ins == 'E')
						ed.x = i , ed.y = j , ed.z = k;
				}
			}
		}
		int ans = bfs();
		if(ans == -1)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n",ans);
	} 
	return 0;
}


