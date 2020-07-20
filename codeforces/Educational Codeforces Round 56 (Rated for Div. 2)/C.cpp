#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 200010;
ll a[sz],b[sz];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1 ; i <= n/2 ; i ++)
		scanf("%I64d",&b[i]);
	a[n] = b[1];
	for(int i = 2 ; i <= n/2 ; i ++)
	{
		a[i] = max(b[i] - a[n-i+2],(ll)0);
		a[i] = max(a[i],a[i-1]);
		a[n-i+1] = b[i] - a[i];
	}
	for(int i = 1 ; i <= n ; i ++)
		printf("%I64d ",a[i]);
	return 0;
}


