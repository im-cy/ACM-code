#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const int sz = 2000100;
int tot = 1;
struct edge
{
	int t,d;
}l[sz];
int hed[sz],nxt[sz];
queue < int > q;
ll dist[sz];
bool use[sz];
void build(int f,int t,int d)
{
	l[tot].t = t;
	l[tot].d = d;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
ll n,a,b,c;
int main()
{
//	freopen("elevator.in","r",stdin);
//	freopen("elevator.out","w",stdout);
	cin >> n >> a >> b >> c;
	if(a > b)
		swap(a,b);
	if(a > c)
		swap(a,c);
	for(int i = 0 ; i < a ; i ++)
	{
		build(i%a,(i+b)%a,b);
		build(i%a,(i+c)%a,c);
	}
	for(int i = 0 ; i < a * 2 ; i ++)
		dist[i%a] = 21474836471111111111ll;
	dist[1%a] = 1;
	q.push(1%a);
	while(!q.empty())
	{
		int f = q.front();
		q.pop();
		use[f%a] = 0;
		for(int i = hed[f] ; i ; i = nxt[i])
		{
			int t = l[i].t;
			if(dist[t%a] > dist[f%a] + l[i].d)
			{
				dist[t%a] = dist[f%a] + l[i].d;
				if(!use[t%a])
				{
					use[t%a] = 1;
					q.push(t%a);
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 0 ; i < a ; i ++)
	{
		if(dist[i] <= n)
			ans += (n - dist[i]) / a + 1;
	}
	cout << ans << endl;
	return 0;
}

