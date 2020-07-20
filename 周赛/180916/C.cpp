#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int sz = 10010;
struct dc
{
	char ins[11];
	int a,b;
}op[sz];
int n;
bool use[sz][311];
int now = 1;
int sum = 0;
void check()
{
	if(op[now].ins[0] == 'a')
	{
		sum += op[now].a;
		sum %= 256;
		now ++;
	}
	else if(op[now].ins[1] == 'e')
	{
		if(sum == op[now].a)
			now = op[now].b;
		else
			now ++;
	}
	else if(op[now].ins[1] == 'n')
	{
		if(sum != op[now].a)
			now = op[now].b;
		else
			now ++;
	}
	else if(op[now].ins[1] == 'l')
	{
		if(sum < op[now].a)
			now = op[now].b;
		else
			now ++;
	}
	else if(op[now].ins[1] == 'g')
	{
		if(sum > op[now].a)
			now = op[now].b;
		else
			now ++;
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%s",op[i].ins);
			if(op[i].ins[0] != 'a')
				scanf("%d%d",&op[i].a,&op[i].b);
			else
				scanf("%d",&op[i].a);
		}
		
		now = 1;
		sum = 0;
		
		while(now < n + 1)
		{
//			printf("# now %d  sum %d\n",now,sum);
			if(use[now][sum])
				break;
			else
				use[now][sum] = 1;
			if(op[now].ins[0] == 'a')
			{
				sum += op[now].a;
				sum %= 256;
				now ++;
			}
			else if(op[now].ins[1] == 'e')
			{
				if(sum == op[now].a)
					now = op[now].b;
				else
					now ++;
			}
			else if(op[now].ins[1] == 'n')
			{
				if(sum != op[now].a)
					now = op[now].b;
				else
					now ++;
			}
			else if(op[now].ins[1] == 'l')
			{
				if(sum < op[now].a)
					now = op[now].b;
				else
					now ++;
			}
			else if(op[now].ins[1] == 'g')
			{
				if(sum > op[now].a)
					now = op[now].b;
				else
					now ++;
			}
		}
		
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 0 ; j <= 255 ; j ++)
				use[i][j] = 0;
		if(now >= (n + 1))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
