#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
const int sz=500009;
using namespace std;
int size[sz],ch[sz][2],rnd[sz],val[sz];
int cnt,n,m,x,y,z,p,a,root,com;

inline int read()
{
	int x = 0 , f = 1;
	char c = getchar();
	while(c > '9' || c < '0')
	{
		if(c == '-')
			f =-1;
		c=getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}

inline void update(int x)
{
	size[x] = 1 + size[ch[x][0]] + size[ch[x][1]];
}
inline int new_node(int x)
{
	size[++cnt] = 1;
	val[cnt] = x;
	rnd[cnt] = rand();
	return cnt;
}

int merge(int A,int B)
{
	if(!A || !B)
		return  A + B;
	if(rnd[A] < rnd[B])
	{
		ch[A][1] = merge(ch[A][1],B);
		update(A);
		return A;
	}
	else
	{
		ch[B][0] = merge(A,ch[B][0]);
		update(B);
		return B;
	}
}

void split(int now,int k,int &x,int &y)
{
	if(!now)
		x = y = 0;
	else
	{
		if(val[now] <= k)
			x = now , split(ch[now][1],k,ch[now][1],y);
		else
			y = now , split(ch[now][0],k,x,ch[now][0]);
		update(now);
	}
}

int kth(int now,int k)
{
	while(1)
	{
		if(k <= size[ch[now][0]])
			now = ch[now][0];
		else if(k == size[ch[now][0]] + 1)
			return now;
		else
			k -= size[ch[now][0]] + 1 , now = ch[now][1];
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int T = read();
	while(T --)
	{
		p = read();
		a = read();
		if(p == 1)
		{//插入x数
			split(root,a,x,y);
			root=merge(merge(x,new_node(a)),y);
		}
		else if(p == 2)
		{//删除x数(若有多个相同的数，因只删除一个)
			split(root,a,x,z);
			split(x,a-1,x,y);
			y=merge(ch[y][0],ch[y][1]);
			root=merge(merge(x,y),z);
		}
		else if(p == 3)
		{//查询x数的排名(若有多个相同的数，因输出最小的排名)
			split(root,a-1,x,y);
			printf("%d\n",size[x]+1);
			root=merge(x,y);
		}
		else if(p == 4)
		{//查询排名为x的数
			printf("%d\n",val[kth(root,a)]);
		}
		else if(p == 5)
		{//求x的前驱(前驱定义为小于x，且最大的数)
			split(root,a-1,x,y);
			printf("%d\n",val[kth(x,size[x])]);
			root=merge(x,y);
		}
		else
		{//求x的后继(后继定义为大于x，且最小的数)
			split(root,a,x,y);
			printf("%d\n",val[kth(y,1)]);
			root=merge(x,y);
		}
	}
	return 0;
}

