//It is made by jump~
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#include <set>
#ifdef WIN32   
#define OT "%I64d"
#else
#define OT "%lld"
#endif
using namespace std;
typedef long long LL;
const int MAXN = 250011;
LL inf;//inf���ܿ�С��
int n,m,ecnt,tot,id[MAXN],k;
int first[MAXN],nxt[MAXN*2],to[MAXN*2],w[MAXN*2];
LL val[MAXN];//����㵽���ϵ���С��Ȩ
int jump[MAXN][19],deep[MAXN];
int que[MAXN],top,Stack[MAXN];
int head[MAXN];
LL f[MAXN];

inline int getint()
{
       int w=0,q=0;
       char c=getchar();
       while((c<'0' || c>'9') && c!='-') c=getchar();
       if (c=='-')  q=1, c=getchar();
       while (c>='0' && c<='9') w=w*10+c-'0', c=getchar();
       return q ? -w : w;
}

struct edge{
    int to,next;
}e[MAXN];

inline LL min(LL x,LL y){ if(x<y) return x;  return y; }

inline void dfs(int x,int fa){
    jump[x][0]=fa; id[x]=++ecnt;//����dfs��
    for(int i=1;i<=18;i++) jump[x][i]=jump[jump[x][i-1]][i-1];
    for(int i=first[x];i;i=nxt[i]) {
    int v=to[i];
    if(v==fa) continue;
    val[v]=min(w[i],val[x]); deep[v]=deep[x]+1;
    dfs(v,x);
    }
}

inline bool cmp(int a,int b){return id[a]<id[b];}

inline int lca(int x,int y){
    if(deep[x]<deep[y]) swap(x,y);
    int t=0; while((1<<t) <= deep[x]) t++;
    t--; for(int i=t;i>=0;i--) if(deep[x]-(1<<i)>=deep[y]) x=jump[x][i];
    if(x==y) return y;
    for(int i=t;i>=0;i--) if(jump[x][i]!=jump[y][i]) { x=jump[x][i]; y=jump[y][i]; } 
    return jump[x][0];
}

inline void link(int x,int y){ if(x==y) return ; e[++ecnt].next=head[x]; head[x]=ecnt; e[ecnt].to=y;}

inline void dp(int x){
    LL lin=0; f[x]=val[x];
    for(int i=head[x];i;i=e[i].next) {
    dp(e[i].to);
    lin+=f[e[i].to];
    }
    head[x]=0;//�˳���ʱ��˳�����
    if(!lin) f[x]=val[x];
    else if(lin<f[x]) f[x]=lin;
}

inline void solve(){//�Ͼ��������1��·��
    m=getint(); for(int i=1;i<=m;i++) que[i]=getint();
    sort(que+1,que+m+1,cmp);//��dfs������
    tot=0; que[++tot]=que[1]; 
    for(int i=2;i<=m;i++) if(lca(que[i],que[tot])!=que[tot]) que[++tot]=que[i];//Ӧ���Ǻ�tot�Ƚ�
    //������Ŀ϶����ü��㣬ֻҪ�ж��ϲ��ļ���
    top=0;Stack[++top]=1; int grand;//�����������
    ecnt=0;
    for(int i=1;i<=tot;i++) {//��������
    grand=lca(Stack[top],que[i]);
    while(1) {
        if(deep[Stack[top-1]]<=deep[grand]) {//�ֱ�������������grand��ȸ��󣡣���
        link(grand,Stack[top]); top--;
        if(Stack[top]!=grand) Stack[++top]=grand;
        break;
        }
        link(Stack[top-1],Stack[top]); top--;
    }
    if(Stack[top]!=que[i]) Stack[++top]=que[i];//��ͬһ����
    }
    top--;
    while(top) link(Stack[top],Stack[top+1]),top--;//ʣ��ļǵ�����
    dp(1);
    printf(OT"\n",f[1]);
}

inline void work(){
    n=getint(); int x,y,z;
    inf=1;for(int i=1;i<=60;i++) inf*=2;
    for(int i=1;i<n;i++) {
    x=getint(); y=getint(); z=getint();
    nxt[++ecnt]=first[x]; first[x]=ecnt; to[ecnt]=y; w[ecnt]=z;
    nxt[++ecnt]=first[y]; first[y]=ecnt; to[ecnt]=x; w[ecnt]=z;
    }
    val[1]=inf; ecnt=0; deep[1]=0; dfs(1,0);
    k=getint(); for(int i=1;i<=k;i++) solve();
}

int main()
{
  work();
  return 0;
}
