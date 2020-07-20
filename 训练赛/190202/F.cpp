#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[21];
int n;
int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d",&num[i]);
	sort(num+1,num+1+n);
	int a = 0 , b = 0;
	int tot = 0;
	for(int i = n ; i >= 1 ; i --)
	{
		
		if(tot == 0)
			a += num[i];
		else
			b += num[i];
		tot ++;
		tot %= 2;
	}
	printf("%d %d\n",a,b);
	return 0;
}
