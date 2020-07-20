#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 10000
using namespace std;
struct gtnd
{
	int mat[2][2];
};
gtnd operator *(const gtnd &a,const gtnd &b)
{
	gtnd ans;
	memset(ans.mat,0,sizeof(ans.mat));
	for(int i = 0 ; i <= 1 ; i ++)
		for(int j = 0 ; j <= 1 ; j ++)
			for(int k = 0 ; k <= 1 ; k ++)
				ans.mat[i][j] = ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % mod;
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
	int n;
	while(scanf("%d",&n) && n != -1)
	{
		if(n == 0)
		{
			puts("0");
			continue;
		}
		gtnd f;
		f.mat[0][0] = 0 , f.mat[0][1] = 1;
		f.mat[1][0] = 0 , f.mat[1][1] = 0;
		gtnd a;
		a.mat[0][0] = 0 , a.mat[0][1] = 1;
		a.mat[1][0] = 1 , a.mat[1][1] = 1;
		
		gtnd ans = f * ksm(a,n);
		printf("%d\n",ans.mat[0][0]);
	}
	return 0;
}
