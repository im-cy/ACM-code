#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int sz = 200010;
ll num[sz];

struct Node_t
{
	int l,r;
	mutable int v;//¸½¼ÓÊý¾Ý 
	Node_t(const int &il,const int &ir,const int &iv) : l(il) , r(ir) , v(iv) {}
	inline bool operator < (const Node_t &o) const {return l < o.l;}
};
set <Node_t> odt;
typedef set<Node_t> :: iterator iter;
int n,m,c;
iter split(int x)
{
	if(x > n)
		return odt.end();
	auto it = -- odt.upper_bound((Node_t){x,0,0});
	if(it -> l == x)
		return it;
	int l = it -> l , r = it -> r , v = it -> v;
	odt.erase(it);
	odt.insert(Node_t(l,x-1,v));
	return odt.insert(Node_t(x,r,v)).first;
}
void assign(int l,int r,int v)
{
	auto itr = split(r+1) , itl = split(l);
	for(auto it = itl ; it != itr ; ++ it)
	{
		num[(*it).v] -= ((*it).r - (*it).l + 1);
		
	}              
	num[v] += r - l + 1;
	odt.erase(itl,itr);
	odt.insert(Node_t(l,r,v));
}

inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}
int main(){
	n=readll(),c=readll(),m=readll();
	odt.insert((Node_t){0,n-1,1});
	num[1] = n;
	while(m--)
	{
		ll p=readll(),x=readll(),a=readll()%n,b=readll()%n;
		ll S=num[p]%n;
		ll m1=(a+S*S)%n;
		ll m2=(a+(S+b)*(S+b))%n;
//		printf("l %lld r %lld\n",m1,m2);
		assign(min(m1,m2),max(m1,m2),x);
	}
	ll maxx=0;
	for(int i = 1 ; i <= c ; i ++)
	{
		maxx=max(maxx,num[i]);
	}
	printf("%I64d\n",maxx);
	return 0;
}

