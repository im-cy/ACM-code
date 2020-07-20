#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int n;
const int sz = 200010;
struct in
{
	ll num;
	char col;
}ins[sz];
ll gcd(ll a,ll b)
{
	if(b == 0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T --)
	{
		ll b = 0, w = 0;
		scanf("%d",&n);
		for(int i = 1 ; i <= n ; i ++)
		{
			scanf("%I64d",&ins[i].num);
			char tmp = getchar();
			while(tmp != 'B' && tmp != 'W')
				tmp = getchar();
			ins[i].col = tmp;
			if(ins[i].col == 'B')
				b += ins[i].num;
			else
				w += ins[i].num;
		}
		if(!b || !w)
		{
			cout << b + w << endl;
			continue;
		}
		ll gcd_ = gcd(b,w);
		b /= gcd_ , w /= gcd_;
		ll B = 0 , W = 0;
		ll ans = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			int k;
			if(ins[i].col == 'B'){
				B += ins[i].num;
				if(W%w) continue;
				k=W/w;
			}else{
				W += ins[i].num;
				if(B%b) continue;
				k=B/b;
			}
			if(k&&B>=k*b&&W>=k*w){
				ans ++;
				B -= k * b;
				W -= k * w;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}

