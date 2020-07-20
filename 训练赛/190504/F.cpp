#include <stdio.h>
#include <cstring>
#include <algorithm>
#define ABS(x) (((x)>0)?(x):(-x))
using namespace std;
using ll=long long;
const int sz=500000;
//用一条竖线从左往右扫描，求面积 
//线段树维护 y 
ll ypos[sz];
int ysize;
ll x1[sz/2],y1[sz/2],x2[sz/2],y2[sz/2];
int n;
struct seg_tree{
	int l,r;
	ll cov;//cover length
	int flag;//how many shapes cover here
	int len(){return r-l+1;}
	int mid(){return (l+r)>>1;}
	ll actual_len(){
		return ypos[r]-ypos[l-1];
	}
	void update(){
		cov=flag*actual_len();
	}
} tree[sz*4];
void build_tree(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	if(l==r) return;
	int mid=tree[p].mid();
	build_tree(p<<1,l,mid);
	build_tree(p<<1|1,mid+1,r);
}
void change(int p,int l,int r){
	if(l<=tree[p].l && r>=tree[p].r && tree[p].flag!=-1){
		tree[p].flag=!tree[p].flag;
		tree[p].update();
//		printf("#%d (%d:%d) %f\n",p,tree[p].l,tree[p].r,tree[p].cov);
		return;
	}
	//push_down
	if(tree[p].flag!=-1){
		tree[p<<1].flag=tree[p<<1|1].flag=tree[p].flag;
		tree[p<<1].update();
		tree[p<<1|1].update();
		tree[p].flag=-1;
	}
	int mid=tree[p].mid();
	if(l<=mid) change(p<<1,l,r);
	if(r>mid) change(p<<1|1,l,r);
	//push_up
	tree[p].cov=tree[p<<1].cov+tree[p<<1|1].cov;
	if(tree[p<<1].flag==tree[p<<1|1].flag){
		tree[p].flag=tree[p<<1].flag;
	}
}
struct Line{
	ll y1,y2;
	ll x;
	bool into;
} line[sz];
bool cmp(const Line &a,const Line &b){
	return a.x<b.x;
}

int discret(ll x){
	return lower_bound(ypos,ypos+ysize,x)-ypos;
}
ll solve(){
	build_tree(1,1,ysize-1);
	ll lastx=0;
	ll sum=0;
	for(int i=0;i<2*n;i++){
		sum+=(line[i].x-lastx)*tree[1].cov;
//		printf("#cur y cover:%f\n",tree[1].cov);
		lastx=line[i].x;
//		printf("#line (%f:%f) %f %d\n",line[i].y1,line[i].y2,line[i].x,line[i].into);
		change(1,discret(line[i].y1)+1,discret(line[i].y2));
	}
	return sum;
}
int main(){
	scanf("%d",&n);
	// memset(tree,0,sizeof(tree));
	// memset(line,0,sizeof(line));
	for(int i=0;i<n;i++){
		scanf("%I64d%I64d%I64d%I64d",&x1[i],&y1[i],&x2[i],&y2[i]);
		line[i].y1=line[n+i].y1=y1[i],line[i].y2=line[n+i].y2=y2[i];
		line[i].x=x1[i],line[i].into=true;
		line[n+i].x=x2[i],line[n+i].into=false;
		ypos[i]=y1[i],ypos[n+i]=y2[i];
	}
	sort(line,line+2*n,cmp);
	ysize=2*n;
	sort(ypos,ypos+ysize);
	ysize=unique(ypos,ypos+ysize)-ypos;
	ll ans=solve();
	printf("%I64d\n",ans);
	return 0;
}
