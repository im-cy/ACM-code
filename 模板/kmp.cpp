#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int sz = 20010;
int nxt[sz];
void getnxt(char s[])
{
    nxt[0] = nxt[1] = 0;
    int l = strlen(s);
    for(int i = 1;i < l;i ++)
    {
        int j = nxt[i];
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
}

int kmp(char s1[],char s2[])
{
    getnxt(s1);
    int ans = 0;
    int n = strlen(s1),m = strlen(s2);
    for(int i = 0,j = 0;i < m;i ++)
    {
        while(j && s1[j] != s2[i]) j = nxt[j];
        if(s1[j] == s2[i]) j ++;
        if(j == n) ans ++;
    }
    return ans;
}
int main()
{
	
	
	
	return 0;
}
