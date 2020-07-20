#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int n;
ll p;
struct mat
{
	ll a[70][70];
}ans;
mat mul(mat a,mat b)
{
	mat nmat;
	memset(nmat.a,0,sizeof(nmat.a));
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			for(int k = 1 ; k <= n ; k ++)
				nmat.a[i][j] += a.a[i][k] * b.a[k][j];
	return nmat;
}
mat add(mat a,mat b)
{
	mat nmat;
	memset(nmat.a,0,sizeof(nmat.a));
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			nmat.a[i][j] = a.a[i][j] + b.a[i][j];
	return nmat;
}

mat mod(mat a)
{
	mat nmat;
	memset(nmat.a,0,sizeof(nmat.a));
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			nmat.a[i][j] = a.a[i][j] % p;
	return nmat;
}
mat a;
mat ksm(int pr)
{
	if(pr == 1)
		return a;
	if(pr == 2)
		return mod(mul(a,a));
	mat temp = mod(ksm(pr/2));
	if(pr % 2 == 1)
		return mod(mul(mod(mul(temp,temp)),a));
	if(pr % 2 == 0)
		return mod(mul(temp,temp));
}
int main()
{
	int k;
	scanf("%d%d%lld",&n,&k,&p);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			scanf("%lld",&a.a[i][j]);
	for(int i = 1 ; i <= n ; i ++)
		a.a[i][i+n] = a.a[i+n][i+n] = 1; 
	int temp_n = n;
	n *= 2;
	ans = ksm(k+1);
	n /= 2;
	for(int i = 1 ; i <= n ; i ++)
	{
		ans.a[i][i+n] --;
		while(ans.a[i][i+n] < 0)
			ans.a[i][i+n] += p;
	}
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
			printf("%lld ",ans.a[i][j+n]);
		puts("");
	}
	return 0;
}
