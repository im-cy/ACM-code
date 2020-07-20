#include<bits/stdc++.h>
using namespace std;
const int sz = 200010;
int hed[sz],nxt[sz],l[sz];
int tot = 1,rd[sz];
void build(int f,int t)
{
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
queue < int > q;
vector< int > v[11];
unordered_map < int , int > mp;
int vi[11];
int n,m;
int T[111];
char ins[11][20101];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i ++)
	{
		char a = getchar();
		while(a < 'a' || a > 'z')
			a = getchar();
		char b = getchar();
		while(b < 'a' || b > 'z')
			b = getchar();
		int len;
		scanf("%d",&len);
		scanf("%s",ins[i]);
	}
	int cnt = 0;
	for(int i = 0 ; i < 26  ; i ++)
	{
		for(int j = 1 ; j <= T[i+'a'] ; j ++)
		{
			v[i].push_back(++ cnt);
			mp[cnt] = i;
		}
		
	} 
	for(int i = 1 ; i <= m ; i ++)
	{
		memset(vi,0,sizeof(vi));
		int len = strlen(ins[i]);
		if(!len)
			continue;
		char last = ins[i][0];
		for(int j = 1 ; j < len ; j ++)
		{
			int u = v[last-'a'][vi[last-'a']];
			vi[last-'a'] ++;
			int v = v[ins[i][j]-'a'][vi[ins[i][j]-'a']];
			last = ins[i][j];
			build(u,v);
		}
	}
	return 0;
}


