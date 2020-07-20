#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[100010];
bool is_check[10000100];
int a[100010][11];
int main()
{
	scanf("%s",s+1);s
	int slen = strlen(s+1);
	for(int i = 1 ; i <= slen ; i ++)
	{
		a[i][1] = s[i] - '0';
		for(int j = 1 ; j < min(7,i); j ++)
		{
			a[i-j][j+1] = a[i-j][j] * 10 + a[i][1];
		}
	}
	for(int i = 1 ; i <= slen ; i ++)
	{
		for(int j = 1 ; j <= min(7,slen - i + 1) ; j ++)
		{
			is_check[a[i][j]] = 1;
		}
	}
	for(int i = 1 ; ; i ++)
	{
		if(!is_check[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}

