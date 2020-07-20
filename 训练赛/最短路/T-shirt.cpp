#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
struct gtnd
{
	ll mat[201][201];
	int m;
};
gtnd operator *(const gtnd &a,const gtnd &b)
{
	gtnd ans;
	ans.m = a.m;
	memset(ans.mat,0,sizeof(ans.mat));
	for(int i = 1 ; i <= ans.m ; i ++)
		for(int j = 1 ; j <= ans.m ; j ++)
			for(int k = 1 ; k <= ans.m ; k ++)
				ans.mat[i][j] = max(ans.mat[i][j],a.mat[i][k] + b.mat[k][j]); 
	return ans;
}
gtnd ksm(const gtnd &a,int p)
{
	if(p == 1)
		return a;
	if(p == 2)
		return a * a;
	gtnd temp = ksm(a,p/2);
	if(p % 2 == 1)
		return temp * temp * a;
	return temp * temp;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		gtnd f;
		f.m = m;
		for(int i = 1 ; i <= m ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				scanf("%lld",&f.mat[i][j]);
		gtnd ans = ksm(f,n-1);
		ll anss = 0;
		for(int i = 1 ; i <= m ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				anss = max(anss,ans.mat[i][j]);
		printf("%lld\n",anss);
	}
	return 0;
}
