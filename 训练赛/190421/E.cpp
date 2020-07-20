#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
char mp[21][21];
struct point
{
	int x[5];
	int y[5];
	int d;	
}s;
int number,n,m,l;
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int gethash(point p)
{
	int ans = 0;
	for(int i = 1 ; i <= number ; i ++)
		ans = ans * 10 + p.x[i] , ans = ans * 10 + p.y[i];
	ans = ans * 10 + p.d;
	return ans;
}
queue < point > q;
map < int , bool > use;
bool check(point nxt,int now)
{
	for(int i = 1 ; i <= number ; i ++)
		if(i == now)
			continue;
		else
		{
			if(nxt.x[now] == nxt.x[i] && nxt.y[now] == nxt.y[i])
				return false;
		}
	return true;
}
int bfs()
{
	s.d = 0;
	use[gethash(s)] = 1;
	q.push(s);
	while(!q.empty())
	{
		point f = q.front();
		q.pop();
		if(mp[f.x[1]][f.y[1]] == 'X')
			return f.d;
		for(int i = 1 ; i <= number ; i ++)
		{
			for(int j = 0 ; j < 4 ; j ++)
			{
				point nxt , temp;
				nxt = f , temp = f;
				nxt.x[i] += step[j][0];
				nxt.y[i] += step[j][1];
				while(nxt.x[i] >= 1 && nxt.x[i] <= n && nxt.y[i] >= 1 && nxt.y[i] <= m && mp[nxt.x[i]][nxt.y[i]] != 'W' && check(nxt,i))
				{
					temp = nxt;
					nxt.x[i] += step[j][0];
					nxt.y[i] += step[j][1];
				}
				nxt = temp;
				nxt.d ++;
				int nxt_hash = gethash(nxt);
				if(!use[nxt_hash] && nxt.d <= 10)
				{
					use[nxt_hash] = 1;
					q.push(nxt);
				}
			}
			
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d%d%d",&number,&n,&m,&l);
	swap(n,m);
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
		{
			char in = getchar();
			while((in < '1' || in > '4') && in != '.' && in != 'X' && in != 'W')
				in = getchar();
			if(in >= '1' && in <= '4')
			{
				if(in == '1')
					s.x[1] = i , s.y[1] = j;
				else if(in == '2')
					s.x[2] = i , s.y[2] = j;
				else if(in == '3')
					s.x[3] = i , s.y[3] = j;
				else
					s.x[4] = i , s.y[4] = j;
				mp[i][j] = '.';
			}
			else
				mp[i][j] = in;
		}
	}
	int ans = bfs();
	if(ans == -1)
		puts("NO SOLUTION");
	else
		printf("%d\n",ans);
	return 0;
}

