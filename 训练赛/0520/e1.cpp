#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200100;
const int CHARSET = 26 , BASE = 'a'; 
struct Trie
{
	int tot,root,child[sz][27];
	int tim[sz][27];
	bool flag[sz];
	Trie()
	{
		memset(tim,0,sizeof(tim));
		memset(child[1],0,sizeof(child[1]));
		flag[1] = 0;
		root = tot = 1;
	}
	void insert(const char *str)
	{
		int *cur = &root;
		for(const char *p = str ; *p ; ++ p)
		{
			cur = &child[*cur][*p - BASE];
			if(*cur == 0)
			{
				*cur = ++ tot;
				memset(child[tot],0,sizeof(child[tot]));
				flag[tot] = false;
			}
		}
		flag[*cur] = true;
	}
	bool query(const char *str)
	{
		int *cur = &root;
		for(const char *p = str ; *p && *cur ; ++ p)
		{
			tim[*cur][*p-BASE] ++;
			cur = &child[*cur][*p-BASE];
		}
		return (*cur && flag[*cur]);
	}
	void find_ans(const char *str)
	{
		int *cur = &root;
		int l = strlen(str);
		for(int i = 0 ; i < l ; i ++)
			cur = &child[*cur][str[i]-BASE];
		bool is = 0;
		for(int i = 0 ; i < 26 ; i ++)
			if(child[*cur][i])
				is = 1;
		if(is)
			printf("%s %s\n",str,str);
		else
		{
			int *cur1 = &root;
			int last = 0;
			for(int i = 0 ; i < l ; i ++)
			{
				if(tim[*cur1][str[i]-BASE] == 1)
				{
					last = i;
					break;
				}
				cur1 = &child[*cur1][str[i]-BASE];
			}
			printf("%s ",str);
			for(int i = 0 ; i <= last ; i ++)
				printf("%c",str[i]);
			puts("");
		}
	}
}solve;
char ins[2010][31];
int main()
{
	int t = 0;
	while(scanf("%s",ins[++t]) != EOF)
		solve.insert(ins[t]);
	for(int i = 1 ; i <= t ; i ++)
		solve.query(ins[i]);
	for(int i = 1 ; i <= t ; i ++)
	{
		solve.find_ans(ins[i]);
	}
	return 0;
}

