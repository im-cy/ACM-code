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
//#include <unordered_map>
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
void print_array(int *a,int n){printf("#");for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');}
typedef long long ll;
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double PI=acos(-1.0);
const double EPS=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}

const int sz=2e5+9;

const int sz_n=2e5+9;
map<string,int> g[sz];
string name[sz];
int oldsz[sz];
int newsz[sz];
int fa[sz];
void init(int n){
	rep(i,0,n+1) g[i].clear();
}
int scnt;
int p;

int newnode(int f){
	++scnt;
	oldsz[scnt]=newsz[scnt]=1;
	fa[scnt]=f;
	return scnt;
}

enum Type{SEP,CD,RM,MKDIR,SZCHANGE};
struct node{
	int type;
	int oldsz,newsz;
	int oldp;
	string x;
	int px;
};
stack<node> s;
inline void undo(){
	if(s.size()==0) {
		puts("ERR");return;
	}
	while(true){
		node &h=s.top();s.pop();
		if(h.type==SEP) {
			break;
		}else if(h.type==CD){
			p=h.oldp;
		}else if(h.type==RM){
			g[p][h.x]=h.px;
		}else if(h.type==MKDIR){
			g[p].erase(h.x);
		}else if(h.type==SZCHANGE){
			newsz[h.oldp]=h.newsz;
			oldsz[h.oldp]=h.oldsz;
		}
	}
	puts("OK");
}


inline void mkdir(const string &x){
	if(g[p].count(x)){
		puts("ERR");return;
	}

	int np=newnode(p);
	name[np]=x;
	g[p][x]=np;
	
	s.push({SEP});
	node h{MKDIR};
	h.x=x;h.px=np;h.oldp=p;
	s.push(h);

	h={SZCHANGE};h.oldp=p;
	h.newsz=newsz[p],h.oldsz=oldsz[p];
	s.push(h);

	newsz[p]++;
	puts("OK");
}
inline void rm(const string &x){
	if(g[p].count(x)==0){
		puts("ERR");
	}else{

		s.push({SEP});
		node h{RM};
		h.x=x;h.px=g[p][x];h.oldp=p;
		s.push(h);

		h={SZCHANGE};h.oldp=p;
		h.newsz=newsz[p],h.oldsz=oldsz[p];
		s.push(h);


		newsz[p]-=newsz[g[p][x]];
		g[p].erase(x);
		puts("OK");
	}
}
inline void cd(const string &x){
	if(x==".."){
		if(p==1){
			puts("ERR");
		}else{

			s.push({SEP});

			node h={SZCHANGE};h.oldp=p;
			h.newsz=newsz[p],h.oldsz=oldsz[p];
			s.push(h);
			
			h={SZCHANGE};h.oldp=fa[p];
			h.newsz=newsz[fa[p]],h.oldsz=oldsz[fa[p]];
			s.push(h);

			h={CD};h.oldp=p;

			puts("OK");
			newsz[fa[p]]+=newsz[p]-oldsz[p];
			oldsz[p]=newsz[p];
			p=fa[p];
		}
	}else if(g[p].count(x)==0) {
		puts("ERR");
	}else{
		s.push({SEP});
		node h={SZCHANGE};h.oldp=p;
		h.newsz=newsz[p],h.oldsz=oldsz[p];
		s.push(h);
		
		int np=g[p][x];
		h={SZCHANGE};h.oldp=np;
		h.newsz=newsz[np],h.oldsz=oldsz[np];
		s.push(h);

		h={CD};h.oldp=p;
		s.push(h);

		p=np;puts("OK");
	}
}
inline void SZ(){//大小没有维护好
	printf("%d\n",newsz[p]);
}
inline void ls(){
	if(g[p].size()==0) {
		puts("EMPTY");
	}else if(g[p].size()<=10){
		for(pair<const string,int> &ps:g[p]){
			puts(ps.first.c_str());
		}
	}else {
		auto it= g[p].begin();
		rep(i,0,5) {
			puts((it->first).c_str());++it;
		}
		puts("...");
		it=g[p].end();
		rep(i,0,5) --it;
		rep(i,0,5){
			// puts((it->first).c_str());++it;
			puts((it->first).c_str());
			++it;
		}
	}
}
inline void dfs(int p){
	puts(name[p].c_str());
	if(g[p].size()<=10){
		for(pair<const string,int> &ps:g[p]){
			// puts(ps.first.c_str());
			dfs(ps.second);
		}
	}else {
		auto it= g[p].begin();
		rep(i,0,5) {
			// puts((it->first).c_str());++it;
			dfs(it->second);++it;
		}
		puts("...");
		it=g[p].end();
		rep(i,0,5) --it;
		rep(i,0,5){
			// puts((it->first).c_str());++it;
			dfs((it->second));
			++it;
		}
	}
}
inline void tree(){
	if(g[p].size()==0) puts("EMPTY");
	else{
		dfs(p);
	}
}



char str[20];string x;char cmd;
			char tmp[20];
inline void solve(){
	while(s.size()) s.pop();
	cmd=0;
	p=1;scnt=1;
	newsz[p]=oldsz[p]=1;
	name[p]="root";
	int n=readll();
	rep(_,0,n){
		scanf("%s",str);
		cmd=str[0];
		if(str[0]=='M'||str[0]=='R'||str[0]=='C'){
			scanf("%s",tmp);x=tmp;
			// cin>>x;
		}
			
		if(cmd=='M'){//mkdir
			mkdir(x);
		}else if(cmd=='R'){//rm
			rm(x);
		}else if(cmd=='C'){//cd
			cd(x);
		}else if(cmd=='S'){//sz
			SZ();
		}else if(cmd=='L'){//ls
			ls();
		}else if(cmd=='T'){//tree
			tree();
		}else if(cmd=='U'){
			undo();
		}
		// cout<<"##curp"<<p<<endl;
	}
}

int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		init(6000);
		solve();
	}
	return 0;
}
/*
1
999
MKDIR dira
CD dirb
CD dira
MKDIR a
MKDIR b
MKDIR c
CD ..
MKDIR dirb
CD dirb
MKDIR x
CD ..
MKDIR dirc
CD dirc
MKDIR y
CD ..
SZ
LS
TREE
RM dira
TREE
UNDO
TREE


RM dirc

SZ

CD dira

SZ

UNDO

SZ

UNDO

SZ


1 100
MKDIR 1
MKDIR 12
MKDIR 124
MKDIR 123
MKDIR 134
MKDIR 165
MKDIR 1675
MKDIR 14537
MKDIR 1876
MKDIR 1678567
MKDIR 1987
MKDIR 19324
MKDIR 198324
MKDIR 19873425
MKDIR 1564

*/
