#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200100;
int tot = 1,root,trie[sz][27];
bool flag[sz];
void init()
{
	memset(trie,0,sizeof(trie));
	memset(flag,0,sizeof(flag));
	root = tot = 1;
}
void insert(char str[])
{
	int cur = 1;
	int l = strlen(str);
	for(int i = 0 ; i < l ; i ++)
	{
		int temp = cur;
		cur = trie[cur][str[i] - 'a'];
		if(cur == 0)
		{
			cur = ++ tot;
			trie[temp][str[i] - 'a'] = tot;
		}
	}
	flag[cur] = true;	
}
bool query(char str[])
{
	int cur = 1;
	int l = strlen(str);
	for(int i = 0 ; i < l ; i ++)
		cur = trie[cur][str[i]-'a'];
	return (cur && flag[cur]);
}
char ins[2010];
int main()
{
	init();
	while(scanf("%s",ins) != EOF)
	{
		if(!query(ins))
		{
			insert(ins);
			puts("0");
		}
		else
			puts("1");
	}
	return 0;
}

