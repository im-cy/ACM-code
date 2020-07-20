#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k;
int ans_r;
int ans_c;
bool check(int i,int j)
{
	if(!(i % 2))
	{
		if(i <= ans_r * 2)
		{
			return true; 
		}
	}
	if(!(j % 2))
	{
		if(j <= ans_c * 2)
			return true;
	}
	return false;
}
int main()
{
	freopen("kotlin.in","r",stdin);
	freopen("kotlin.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int r = (n+1) / 2;
	int c = (m+1) / 2;
	bool flag = 0;
	for(int i = 1 ; i <= r ; i ++)
	{
		for(int j = 1 ; j <= c ; j ++)
		{
			if(i * j == k)
			{
				flag = 1;
				ans_r = i;
				ans_c = j;
				break;
			}
		}
		if(flag)
			break;
	}
	ans_r --;
	ans_c --;
	if(!flag)
		puts("Impossible");
	else
	{
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
			{
				if(check(i,j))
					printf("#");
				else
					printf(".");
			}
			puts("");
		}
		
	}	
	return 0;
}
 
