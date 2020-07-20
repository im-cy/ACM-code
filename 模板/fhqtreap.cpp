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
		{//����x��
			split(root,a,x,y);
			root=merge(merge(x,new_node(a)),y);
		}
		else if(p == 2)
		{//ɾ��x��(���ж����ͬ��������ֻɾ��һ��)
			split(root,a,x,z);
			split(x,a-1,x,y);
			y=merge(ch[y][0],ch[y][1]);
			root=merge(merge(x,y),z);
		}
		else if(p == 3)
		{//��ѯx��������(���ж����ͬ�������������С������)
			split(root,a-1,x,y);
			printf("%d\n",size[x]+1);
			root=merge(x,y);
		}
		else if(p == 4)
		{//��ѯ����Ϊx����
			printf("%d\n",val[kth(root,a)]);
		}
		else if(p == 5)
		{//��x��ǰ��(ǰ������ΪС��x����������)
			split(root,a-1,x,y);
			printf("%d\n",val[kth(x,size[x])]);
			root=merge(x,y);
		}
		else
		{//��x�ĺ��(��̶���Ϊ����x������С����)
			split(root,a,x,y);
			printf("%d\n",val[kth(y,1)]);
			root=merge(x,y);
		}
	}
	return 0;
}

