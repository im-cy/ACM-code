#include <stdio.h>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
#define LOG(a) cout<<'#'<<a<<endl
void print_array(int *a,int n){printf("#");for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');}
typedef long long ll;
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double EPS=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int mod = 1000000; 
const int sz=1e6+9;


int cnt, rt;

struct splayNode{
	int key, num, size, fa, son[2];
	ll max, v;
	ll add;
	bool inv;
}t[sz];
void init(){
	mem(t,0);
	cnt=rt=0;
}
inline void pushUp(int x){
	// t[x].max=t[x].v;
	// if(t[x].son[0]) t[x].max=max(t[x].max,t[t[x].son[0]].max);
	// if(t[x].son[1]) t[x].max=max(t[x].max,t[t[x].son[1]].max);
	t[x].size=t[t[x].son[0]].size+t[t[x].son[1]].size+t[x].num;
}

inline void pushDown(int x){
	// return;
	// if(t[x].add){
	// 	if(t[x].son[0]){
	// 		t[t[x].son[0]].v+=t[x].add;
	// 		t[t[x].son[0]].max+=t[x].add;
	// 		t[t[x].son[0]].add+=t[x].add;
	// 	}
	// 	if(t[x].son[1]){
	// 		t[t[x].son[1]].v+=t[x].add;
	// 		t[t[x].son[1]].max+=t[x].add;
	// 		t[t[x].son[1]].add+=t[x].add;
	// 	}
	// 	t[x].add=0;
	// }
	// if(t[x].inv){
	// 	// swap(t[x].son[0],t[x].son[1]);
	// 	if(t[x].son[0]) {
	// 		swap(t[t[x].son[0]].son[0],t[t[x].son[0]].son[1]);
	// 		t[t[x].son[0]].inv^=t[x].inv;
	// 	}
	// 	if(t[x].son[1]){
	// 		swap(t[t[x].son[1]].son[0],t[t[x].son[1]].son[1]);
	// 		t[t[x].son[1]].inv^=t[x].inv;
	// 	}
	// 	t[x].inv=0;
	// }
}

inline int newnode(int key, int fa,int v) {//新建一个节点并返回
	++cnt;
	t[cnt].key=key;
	t[cnt].num=t[cnt].size=1;
	t[cnt].fa=fa;
	t[cnt].son[0]=t[cnt].son[1]=0;
	t[cnt].v=v;
	return cnt;
}

inline void rot(int x, int p){ //0左旋 1右旋
	int y=t[x].fa;
	pushDown(y);
	pushDown(x);
	t[y].son[!p]=t[x].son[p];
	t[t[x].son[p]].fa=y;
	t[x].fa=t[y].fa;
	if(t[x].fa) t[t[x].fa].son[t[t[x].fa].son[1] == y]=x;
	t[x].son[p]=y;
	t[y].fa=x;
	pushUp(y);
	pushUp(x);
}

void splay(int x, int to){ //将x节点移动到to的子节点中
	while(t[x].fa != to){
		if(t[t[x].fa].fa == to) rot(x, t[t[x].fa].son[0] == x);
		else{
			int y=t[x].fa, z=t[y].fa;
			int p=(t[z].son[0] == y);
			if(t[y].son[p] == x) rot(x, !p), rot(x, p); //之字旋
			else rot(y, p), rot(x, p); //一字旋
		}
	}
	pushUp(x);
	if(to == 0) rt=x;
}

int getKth(int p, int to){ //返回第p小的节点 并移动到to的子节点中
	if(!rt || p > t[rt].size|| p<=0) return 0;
	int x=rt;
	pushDown(x);
	while(x){
		// LOG("currank"<<t[t[x].son[0]].size+1);
		if(p >= t[t[x].son[0]].size+1 && p <= t[t[x].son[0]].size+t[x].num) break;
		if(p > t[t[x].son[0]].size+t[x].num){
			p-=t[t[x].son[0]].size+t[x].num;
			x=t[x].son[1];
		}else{
			x=t[x].son[0];
		}
		pushDown(x);
	}
	splay(x, to);
	return x;
}

int find(int key){ //返回值为key的节点 若无返回0 若有将其转移到根处
	if(!rt) return 0;
	int x=rt;
	while(x){
		pushDown(x);
		if(t[x].key == key) break;
		x=t[x].son[key > t[x].key];
	}
	if(x) splay(x, 0);
	return x;
}

int first(){
	if(!rt) return 0;
	int x=rt;
	while(t[x].son[0]){
		pushDown(x);
		x=t[x].son[0];
	}
	splay(x,0);
	return x;
}
int last(){
	if(!rt) return 0;
	int x=rt;
	while(t[x].son[1]){
		pushDown(x);
		x=t[x].son[1];
	}
	splay(x,0);
	return x;
}

int prev(){ //返回根节点的前驱 非重点
	if(!rt || !t[rt].son[0]) return 0;
	int x=t[rt].son[0];
	while(t[x].son[1]){
		pushDown(x);
		x=t[x].son[1];
	}
	return x;
}

int succ(){ //返回根结点的后继 非重点
	if(!rt || !t[rt].son[1]) return 0;
	int x=t[rt].son[1];
	while(t[x].son[0]){
		pushDown(x);
		x=t[x].son[0];
	}
	return x;
}

void insert(int key,int v){ //插入key值
	if(!rt) {rt=newnode(key, 0,v);return;}
	int x=rt, y=0;
	while(x){
		pushDown(x);
		y=x;
		if(t[x].key == key){
			t[x].num++;
			t[x].size++;
			break;
		}
		t[x].size++;
		x=t[x].son[key > t[x].key];
	}
	if(!x) x=t[y].son[key > t[y].key]=newnode(key, y,v);
	splay(x, 0);
}

void erase(int key){ //删除值为key的节点1个
	int x=find(key);
	if(!x) return;
	if(t[x].num>1){
		t[x].num--;
		pushUp(x);
		return;
	}
	int y=t[x].son[0];
	while(t[y].son[1]) y=t[y].son[1];
	int z=t[x].son[1];
	while(t[z].son[0]) z=t[z].son[0];
	if(!y && !z){
		rt=0;
		return;
	}
	if(!y){
		splay(z, 0);
		t[z].son[0]=0;
		pushUp(z);
		return;
	}
	if(!z){
		splay(y, 0);
		t[y].son[1]=0;
		pushUp(y);
		return;
	}
	splay(y, 0);
	splay(z, y);
	t[z].son[0]=0;
	pushUp(z);
	pushUp(y);
}

int getRank(int key){ //获得值<=key的节点个数
	if(!find(key)){
		insert(key,0);
		int tmp=t[t[rt].son[0]].size;
		erase(key);
		return tmp;
	}else
		return t[t[rt].son[0]].size+t[rt].num;
}

void eraseRange(int l, int r){ //删除值在[l, r]中的所有节点 l!=r
	if(!find(l)) insert(l,0);
	int p=prev();
	splay(p, 0);
	if(!find(r)) insert(r,0);
	int q=succ();
	splay(q, 0);
	if(!p && !q){
		rt=0;
		return;
	}
	if(!p){
		t[rt].son[0]=0;
		pushUp(rt);
		return;
	}
	if(!q){
		splay(p, 0);
		t[rt].son[1]=0;
		pushUp(rt);
		return;
	}
	splay(p, q);
	t[p].son[1]=0;
	pushUp(p);
	pushUp(q);
}
int getRange(int l,int r){//将区间[l,r]旋转到一起，返回子树根节点
	// l--;r++;
	getKth(l+1,0);
	int p=prev();
	splay(p, 0);
	getKth(r+1,0);
	int q=succ();
	splay(q, 0);
	// LOG(t[p].key<<","<<t[q].key);
	if(!p && !q){
		rt=0;
		return 0;
	}
	if(!p){
		t[rt].son[0]=0;
		pushUp(rt);
		return 0;
	}
	if(!q){
		splay(p, 0);
		t[rt].son[1]=0;
		pushUp(rt);
		return 0;
	}
	splay(p, q);
	pushUp(p);
	pushUp(q);
	return t[p].son[1];
}


int main()
{
    int n,op,x;
    scanf("%d",&n);
    insert((int)INF,0);
    insert(-(int)INF,0);
    ll ans = 0 , sum = 0;
    for(int i = 1 ; i <= n ; i ++)
	{
        scanf("%d%d",&op,&x);
        if(!sum)
        {
        	if(op)
        		sum ++;
        	else
        		sum --;
        	 insert(x,0);
        }
        else
        {
        	if(sum > 0)
        	{
        		if(op)
        			sum ++ , insert(x,0);
        		else
        		{
        			sum --;
        			insert(x,0);
        			int pr = t[prev()].key;
        			int nx = t[succ()].key;
        			if(pr == -INF)
        				ans += (nx - x)%mod , erase(nx);
        			else if(nx == INF)
        				ans += (x - pr)%mod , erase(pr);
        			else
        			{
        				if((nx - x) < (x - pr))
        					ans += (nx - x)%mod , erase(nx);
						else
							ans += (x - pr)%mod , erase(pr);
        			}
        			erase(x);
        		}
        	}
        	else
        	{
        		if(!op)
        			sum -- , insert(x,0);
        		else
        		{
        			sum ++;
        			insert(x,0);
        			int pr = t[prev()].key;
        			int nx = t[succ()].key;
        			if(pr == -INF)
        				ans += (nx - x)%mod , erase(nx);
        			else if(nx == INF)
        				ans += (x - pr)%mod , erase(pr);
        			else
        			{
        				if((nx - x) < (x - pr))
        					ans += (nx - x)%mod , erase(nx);
						else
							ans += (x - pr)%mod , erase(pr);
        			}
        			erase(x);
        		}
        	}
        }
//	    printf("ans %d\n",ans);
        ans %= mod;
     /* if(1==op) Insert(x);
        else if(2==op) del(x);
        else if(3==op) printf("%d\n",findnum(x));
        else if(4==op) printf("%d\n",data[kth(x,1)]);
        else if(5==op) printf("%d\n",pred(x));
        else if(6==op) printf("%d\n",succ(x));*/
    }
    printf("%lld\n",ans%mod);
    return 0;
}
