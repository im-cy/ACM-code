#include<bits/stdc++.h>
using namespace std;
const int sz = 1050;
int r,c;

char mp[sz][sz];
char tg[sz][sz];
bool rr[sz],cc[sz];

int check_c(int k)
{
	int tot = 0;
	for(int i = 1 ; i <= c ; i ++)
	{
		if(tg[k][i] == 'X' && tg[k][i] != mp[k][i])
			tot ++;
	}
}
int check()
{
	int ans = 0;
	for(int i = 1 ; i <= r ; i ++)
	{
		int tmp = check_c(i);
		if(tmp == -1)
			return -1;
		ans += tmp;
	}
	return ans;
}

int main()
{
	while(scanf("%d%d",&r,&c)  != EOF)
	{
		for(int i = 1 ; i <= r ; i ++)
		{
			for(int j = 1 ; j <= c ; j ++)
			{
				char ins = getchar();
				while(ins != 'X' && ins != 'O')
					ins = getchar();
				mp[i][j] = ins;
			}
		}
		for(int i = 1 ; i <= r ; i ++)
		{
			for(int j = 1 ; j <= c ; j ++)
			{
				char ins = getchar();
				while(ins != 'X' && ins != 'O')
					ins = getchar();
				tg[i][j] = ins;
			}
		}
		int ans = check();
		printf("%d\n",ans);
	}
	
	return 0;
}

