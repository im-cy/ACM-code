#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
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
int block_num;//整块的数量 
void block_init()
{
	block_num = sqrt(n); 
	for(int i = 1 ; i <= n ; i ++)
	{
		find_block[i] = (i-1) / block_num + 1; 
	}
	return ;
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
	if(find_block[l] != find_block[r]) //不重合的话将右端点的块也暴力处理 
		for(int i = block_l(r) ; i <= r ; i ++) 
			num[i] += c;
	for(int i = find_block[l] + 1 ; i <= find_block[r] - 1 ; i ++)//每个块 O(1) 
		block[i].num += c;
	return ; 
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
			printf("%lld\n",num[r]+block[find_block[r]].num);
	} 
	return 0;
}
/*
10
1 1 1 1 1 1 1 1 1 1
*/
