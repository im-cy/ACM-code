#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int sz = 2000100;
int n;
struct point
{
	int x,y;
}in_data[sz];
int cf[sz];
int main()
{
	freopen("intel.in","r",stdin);
	freopen("intel.out","w",stdout);
    scanf("%d",&n);
    int min_x = 214748364 , max_x = 0;
    int min_y = 214748364 , max_y = 0;
    for(int i = 1 ; i <= n ; i ++)
        scanf("%d%d",&in_data[i].x,&in_data[i].y) , in_data[i].x += 1e6 + 1 , in_data[i].y += 1e6 + 1 ,
		max_x = max(max_x,in_data[i].x) , min_x = min(min_x,in_data[i].x) ,
		max_y = max(max_y,in_data[i].y) , min_y = min(min_y,in_data[i].y);
    in_data[n+1] = in_data[1];
    n ++;
    for(int i = 2 ; i <= n ; i ++)
    {
    	if(in_data[i-1].y == in_data[i].y)
    		cf[min(in_data[i-1].x,in_data[i].x)] ++ , cf[max(in_data[i-1].x,in_data[i].x)] --;
    }
    ll ans = 0;
    for(int i = min_x ; i <= max_x ; i ++)
    	cf[i] += cf[i-1];
    for(int i = min_x ; i <= max_x ; i ++)
    	ans += cf[i];
    ans -= (max_x - min_x) * 2;
    memset(cf,0,sizeof(cf));
    for(int i = 2 ; i <= n ; i ++)
    {
    	if(in_data[i-1].x == in_data[i].x)
    		cf[min(in_data[i-1].y,in_data[i].y)] ++ , cf[max(in_data[i-1].y,in_data[i].y)] --;
    }
    for(int i = min_y ; i <= max_y ; i ++)
    	cf[i] += cf[i-1];
    for(int i = min_y ; i <= max_y ; i ++)
    	ans += cf[i];
    ans -= (max_y - min_y) * 2;
    cout << ans << endl;
    return 0;
}
