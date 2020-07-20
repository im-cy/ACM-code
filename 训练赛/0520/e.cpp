#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200100;
char ins[2010][31];
int tri[20010][31];
int tot = 1;
bool flag[20010];
bool pre[20010];
bool check(int p)
{
	for(int i = 1 ; i <= 26 ; i ++)
		if(tri[p][i])
			return true;
	return false;
}
bool find(int i)
{
	int now = 1;
	int l = strlen(ins[i]);
	for(int j = 0 ; j < l ; j ++)
	{
		if(!tri[now][ins[i][j]-'a'+1])
			return false;
		now = tri[now][ins[i][j]-'a'+1];
	}
	return flag[now];
}
int main()
{
	int t = 0;
	while(scanf("%s",ins[++t]) != EOF)
	{
		int n = strlen(ins[t]);
		int now = 1;
		for(int i = 0 ; i < n ; i ++)
		{
			if(!tri[now][ins[t][i]-'a'+1])
				tri[now][ins[t][i]-'a'+1] = ++ tot;
			now = tot;
		}
		flag[tot] = 1;
	}
/*	for(int i = 1 ; i <= tot ; i ++)
	{
		if(flag[i] && check(i))
			pre[i] = 1;
	}*/
	for(int i = 1 ; i <= t ; i ++)
	{
		printf("%d\n",find(i));
	}
	return 0;
}

