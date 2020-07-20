#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
const int sz = 200010;
int n;//数组长度 
ll num[sz];//初始数组 
int find_block[sz];//第i个数属于第find_block[i]块 
struct block_
{
	ll num;
}block[sz];//记录块内信息
vector < int > ve[sz];
int block_num;//整块的数量 
void block_init()
{
	block_num = sqrt(n); 
	for(int i = 1 ; i <= n ; i ++)
	{
		find_block[i] = (i-1) / block_num + 1;
		ve[find_block[i]].push_back(num[i]);
	}
	for(int i = 1 ; i <= find_block[n] ; i ++)
		sort(ve[i].begin(),ve[i].end());
	return ;
}
void reset(int x)//第x个块 
{
	ve[x].clear();
	int l = (x-1) * block_num + 1 , r = min(x*block_num,n);
	for(int i = l ; i <= r ; i ++)
		ve[x].push_back(num[i]);
	sort(ve[x].begin(),ve[x].end());
}
//找到x所属块的左右端点 
int block_l(int x)
{
	return (find_block[x]-1) * block_num + 1;
}
int block_r(int x)
{
	return find_block[x] * block_num;
}
void change(int l,int r,int c)
{
	for(int i = l ; i <= min(r,block_r(l)) ; i ++) //块内暴力 
		num[i] += c;
	reset(find_block[l]);
	if(find_block[l] != find_block[r]) //不重合的话将右端点的块也暴力处理 
	{
		for(int i = block_l(r) ; i <= r ; i ++) 
			num[i] += c;
		reset(find_block[r]);
	}
	for(int i = find_block[l] + 1 ; i <= find_block[r] - 1 ; i ++)//每个块 O(1) 
		block[i].num += c;
	return ; 
}
int ask(int l,int r,int c)//查询lr中小于c的个数 
{
	int ans = 0;
	for(int i = l ; i <= min(r,block_r(l)) ; i ++) //块内暴力 
		if(num[i] + block[find_block[l]].num < c)
			ans ++;
	if(find_block[l] != find_block[r]) //不重合的话将右端点的块也暴力处理 
	{
		for(int i = block_l(r) ; i <= r ; i ++) 
			if(num[i] + block[find_block[r]].num < c)
				ans ++;
	}
	for(int i = find_block[l] + 1 ; i <= find_block[r] - 1 ; i ++)//每个块 O(1) 
	{
		int x = c - block[i].num;
		ans += lower_bound(ve[i].begin(),ve[i].end(),x) - ve[i].begin();
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%lld",&num[i]);
	block_init();
	for(int i = 1 ; i <= n ; i ++)
	{
		int opt,l,r;
		ll c;
		scanf("%d%d%d%lld",&opt,&l,&r,&c);
		if(opt == 0)
			change(l,r,c);
		if(opt == 1)
			printf("%d\n",ask(l,r,c*c));
	} 
	return 0;
}
