#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char ins[201];
char mp[201][201];
int main()
{
	int n;
	while(scanf("%d",&n) && n)
	{
		memset(ins,0,sizeof(ins));
		memset(mp,0,sizeof(mp));
		scanf("%s",ins);
		int l = strlen(ins);
		l = l / n;
		int tot = 0;
		for(int i = 0 ; i < l ; i ++)
		{
			if(!(i%2))
			for(int j = 0 ; j < n ; j ++)
				mp[i][j] = ins[tot++];
			else
			for(int j = n - 1 ; j >= 0 ; j --)
				mp[i][j] = ins[tot++];
		}
		
		for(int j = 0 ; j < n ; j ++)
		{
			for(int i = 0 ; i < l ; i ++)
			{
				printf("%c",mp[i][j]);
			}
		}
		puts("");
	}
	return 0;
}


