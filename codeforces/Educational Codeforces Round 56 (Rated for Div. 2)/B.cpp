#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char ins[200100];
int is[101];
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		memset(is,0,sizeof(is));
		memset(ins,0,sizeof(ins));
		scanf("%s",ins);
		int l = strlen(ins);
		int kinds = 0;
		for(int i = 0 ; i < l ; i ++)
		{
			if(!is[ins[i]-'a'+1])
			{
				kinds ++;
			}
			is[ins[i]-'a'+1] ++;
		}
		if(kinds <= 1)
			puts("-1");
		else
		{
			for(int i = 1 ; i <= 26 ; i ++)
			{
				while(is[i] --)
					printf("%c",i+'a'-1);
			}
			puts("");
		}
	}
	return 0;
}
