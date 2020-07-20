#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pd[200010];
int player[241][20];//[0]当前牌数 
int n,m;
int cut = 1;
void init()
{
	cut = 1;
	memset(pd,0,sizeof(pd));
	memset(player,0,sizeof(player));
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		scanf("%d",&pd[i]);
		if(pd[i] == 1)
			pd[i] = 14;
		if(pd[i] == 2)
			pd[i] = 15;
	}
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= 5 ; j ++)
		{
			player[i][pd[cut]] ++;
			cut ++;
			player[i][0] ++;
		}
	return ;
}
void get_card()
{
	if(cut > m)
		return ;
	for(int i = 1 ; i <= n ; i ++)
		if(cut <= m)
		{
			player[i][pd[cut]] ++;
			cut ++;
			player[i][0] ++;
		}
	return ;
}
bool is_end_check()
{
	for(int i = 1 ; i <= n ; i ++)
		if(player[i][0] == 0)
			return true;
	return false;
}
int find_card(int p)
{
	for(int i = 1 ;  i <= 15 ; i ++)
		if(player[p][i] > 0)
			return i;
	return -1;
}
int find_fucker(int pler,int now_p)
{
	if(now_p == 15)
		return -1;
	for(int i = pler + 1 ; i <= n ; i ++)
		if(player[i][now_p+1] || player[i][15])
			return i;
	for(int i = 1 ; i < pler ; i ++)
		if(player[i][now_p+1] || player[i][15])
			return i;
	return -1;
}
void testprint(int p)
{
	printf("%dth player's card\n",p);
	for(int i = 1 ; i <= 15 ; i ++)
		printf("%d ",player[p][i]);
	puts("");
}
int main()
{
	int t;
	int cas = 0;
	scanf("%d",&t);
	while(t --)
	{
		cas ++;
		init();
		int now_player = 1;
		int now_p = find_card(now_player);
		player[now_player][now_p] --;
		player[now_player][0] --;
		while(!is_end_check())
		{
		//	for(int i = 1 ; i <= n ; i ++)
		//		testprint(i);
		//	puts("");
			int next_player = find_fucker(now_player,now_p);//注意2 
			while(next_player != -1)
			{
				now_player = next_player;
				now_p ++;
				if(player[now_player][now_p] > 0)
					player[now_player][now_p] --;
				else
					player[now_player][15] -- , now_p = 15;
				player[now_player][0] --;
				next_player = find_fucker(now_player,now_p);
				if(player[now_player][0] <= 0)
					break;
			}
			{
				get_card();
				now_p = find_card(now_player);
				player[now_player][now_p] --;
				player[now_player][0] --;
				if(player[now_player][0] <= 0)
					break;
			}
		}
		printf("Case #%d:\n",cas);
		for(int i = 1 ; i <= n ; i ++)
		{
				int ans = 0;
				player[i][1] += player[i][14];
				player[i][2] += player[i][15];
				for(int j = 1 ; j <= 13 ; j ++)
					ans += player[i][j] * j;
				if(ans == 0)
					puts("Winner");
				else 
					printf("%d\n",ans);

		}
	}
	 
	return 0;
}
 
