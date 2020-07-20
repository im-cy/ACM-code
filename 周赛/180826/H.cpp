#include<bits/stdc++.h>
#define N 205
#define ll long long
using namespace std;
const double eps = 1e-8;
const int MAX = 1010;
int n;
double a[N][N],del;
long long su[MAX],cnt;
bool isprime[MAX];
void prime()
{
    cnt=1;
    memset(isprime,1,sizeof(isprime));//初始化认为所有数都为素数
    isprime[0]=isprime[1]=0;//0和1不是素数
    for(long long i=2;i<=MAX;i++)
    {
        if(isprime[i])
            su[cnt++]=i;//保存素数i
        for(long long j=1;j<cnt&&su[j]*i<MAX;j++)
        {
            isprime[su[j]*i]=0;//筛掉小于等于i的素数和i的积构成的合数
        }
    }
}

bool gauss()
{
    for(int i = 1 ; i <= n ; i ++)
	{
        int k = i;
        for(int j = i + 1 ; j <= n ; j ++)
			if(fabs(a[j][i]) > fabs(a[k][i]))
				k = j;
        if(fabs(del=a[k][i]) < eps)
			return 0;
        for(int j = i ; j <= n + 1 ; j ++)
			swap(a[i][j],a[k][j]);
        for(int j = i ; j <= n + 1 ; j ++)
			a[i][j] /= del;
        for(k = 1 ; k <= n ; k ++)
			if(k != i)
			{
         	   del = a[k][i];
            	for(int j = i ; j <= n + 1 ; j ++)
					a[k][j] -= a[i][j] * del;
        	}
    }
    return 1;
}
ll gcd(ll a,ll b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	prime();
	while(t --)
    {
    	memset(a,0,sizeof(a));
    	del = 0;
    	n = 5;
  		for(int i = 1 ; i <= 5 ; i ++)
    	{
    		double x,y;
    		cin >> x >> y;
			a[i][1] = x * x;
			a[i][2] = x * y;
			a[i][3] = y * y;
			a[i][4] = x;
			a[i][5] = y;
			a[i][6] = -1;
    	}
    	bool flag = gauss();
    	if(!flag)
			puts("IMPOSSIBLE");
    	else 
		{
			double A,B,C,E,D,Xc,Yc,a_2,b_2;
			A = a[1][n+1];
			B = a[2][n+1];
			C = a[3][n+1];
			D = a[4][n+1];
			E = a[5][n+1];
			double q, p;
			Xc = (B*E - 2*C*D);
			Yc = (B*D - 2*A*E);
			p = (2 * (A*Xc*Xc + C*Yc*Yc + B*Xc*Yc - (4*A*C - B*B)*(4*A*C - B*B))) * (2 * (A*Xc*Xc + C*Yc*Yc + B*Xc*Yc - (4*A*C - B*B)*(4*A*C - B*B)));
			q = (A+C) * (A+C) - ((A-C)*(A-C) + B*B);
			q *= (4*A*C - B*B)*(4*A*C - B*B) * (4*A*C - B*B)*(4*A*C - B*B);
			double temp = p / q;
            ll ans_p = temp * 21e10 , ans_q = 21e10;
			while(gcd(ans_p,ans_q) != 1)
			{
				ll temp_gcd = gcd(ans_p,ans_q);
				ans_p /= temp_gcd;
				ans_q /= temp_gcd;
			}
			if(ans_q != 1)
				printf("%lld/%lld\n",ans_p,ans_q);
			else
				printf("%lld\n",ans_p);
//			for(int i = 1 ; i <= n ; i ++)
//				printf("%.2lf\n",a[i][n+1]);
		}
    }
    return 0;
}
