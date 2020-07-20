#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 2147483641
using namespace std;
const int sz = 200010;
char temp[sz];
char s1[sz];
char s2[sz];
int n;
void trans(int x)
{
	if(temp[x] == '1')
		temp[x] = '0';
	else if(temp[x] == '0')
		temp[x] = '1';
	return ;
}
int sol1()
{
	for(int i = 1 ; i <= n ; i ++)
		temp[i] = s1[i];
	int ans = 0;
	for(int i = 1 ; i < n ; i ++)
		if(temp[i] != s2[i])
			trans(i),trans(i+1),ans ++;
	if(temp[n] != s2[n])
		return inf;
	return ans;
}
int sol2()
{
	for(int i = 1 ; i <= n ; i ++)
		temp[i] = s1[i];
	trans(1) , trans(n);
	int ans = 1;
	for(int i = 1 ; i < n ; i ++)
		if(temp[i] != s2[i])
			trans(i),trans(i+1),ans ++;
	if(temp[n] != s2[n])
		return inf;
	return ans;
}
int main()
{
	scanf("%s%s",s1+1,s2+1);
	n = strlen(s1+1);
	int ans = inf;
	for(int i = 1 ; i <= n ; i ++)
	{
		int tp = s1[n];
		for(int j = n ; j >= 2 ; j --)
			s1[j] = s1[j-1];
		s1[1] = tp;
		ans = min(min(sol1(),sol2()),ans);
	}
	if(ans == inf)
		puts("-1");
	else
		printf("%d\n",ans);
	return 0;
}

