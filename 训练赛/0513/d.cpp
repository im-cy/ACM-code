#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 200010;
int nxt[sz];
char ins[sz];
void getnxt(char s[])
{
	memset(nxt,0,sizeof(nxt));
    nxt[0] = nxt[1] = 0;
    int l = strlen(s);
    for(int i = 1;i < l;i ++)
    {
        int j = nxt[i];
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
    return ;
}
int main()
{
	int n;
	scanf("%d\n",&n);
	for(int i = 1 ; i <= n ; i ++)
	{
		scanf("%s",ins);
		getnxt(ins);
		int len = strlen(ins);
		int l = len - nxt[len];
		if(len % l == 0 && l != len)
			puts("0");
		else
			printf("%d\n",l - len % l);
	}
	return 0;
}
