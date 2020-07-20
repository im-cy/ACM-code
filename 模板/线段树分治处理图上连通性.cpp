#include<bits/stdc++.h>
using namespace std;
#define Inc(i,L,R) for(register int i=(L);i<=(R);++i)
#define Red(j,R,L) for(register int j=(R);j>=(L);--j)
const int N = 5010,M = 5e5+10;
struct Data{
    int x,y;
};
Data e[M],q[M];
int cnte,cntq;
struct Union{
    int p[N],siz[N];
    stack<Data>stk;//我们开一个栈来保存合并了哪些点
    inline void Reset(int n)
    {
        Inc(i,1,n)p[i]=i;
        Inc(i,1,n)siz[i]=1;
    }
    inline int Findfa(int x){
        while(x!=p[x])
            x=p[x];
        return x;
    }
    inline void Merge(int idx){
        int x=e[idx].x,y=e[idx].y;
        int fx=Findfa(x),fy=Findfa(y);
        if(fx==fy)
            return ;
        if(siz[fx]>siz[fy])
            swap(fx,fy);
        stk.push((Data){fx,fy});
        siz[p[fx]=fy]+=siz[fx];
    }
    inline void Delete(int Presiz){//撤销操作
        while(stk.size()>Presiz)
        {
            Data tmp=stk.top();
            stk.pop();
            siz[tmp.y]-=siz[p[tmp.x]=tmp.x];
        }
    }
    inline bool Connect(int idx){
        return Findfa(q[idx].x)==Findfa(q[idx].y);
    }
}u;
struct SegMent{
    struct Tree{
        bool Loc;
        int L,r,idx;
        vector<int>vec;//存储边的编号
    }t[M<<2];
#define Ls v<<1
#define rs v<<1|1
    inline void build(int v,int L,int r){
        t[v]=(Tree){0,L,r,0};
        t[v].vec.clear();
        if(L==r)return ;
        int Mid=L+r>>1;
        build(Ls,L,Mid),build(rs,Mid+1,r);
    }
    inline void update(int v,int A,int b,int idx){//每条边在哪些时刻出现过
        if(t[v].L>b||t[v].r<A)return ;
        if(A<=t[v].L&&t[v].r<=b)
            return t[v].vec.push_back(idx),void();
        update(Ls,A,b,idx),update(rs,A,b,idx);
    }
    inline void LocQ(int v,int Time,int idx){
        if(t[v].L>Time||t[v].r<Time)
            return ;
        t[v].Loc=1;//小加速？不用完全遍历整个区间
        if(t[v].L==t[v].r)
            return t[v].idx=idx,void();//问题的编号
        LocQ(Ls,Time,idx),LocQ(rs,Time,idx);
    }
    inline void Stat(int v)
    {
        if(!t[v].Loc)
            return ;
        int tmpsiz=u.stk.size();
        if(t[v].vec.size())
            Inc(i,0,t[v].vec.size()-1)
                u.Merge(t[v].vec[i]);
        if(t[v].L==t[v].r)
            return u.Connect(t[v].idx)?puts("Y"):puts("N"),void();
        Stat(Ls),Stat(rs);
        u.Delete(tmpsiz);
    }
}t;
int n,m,pre[M];
#define pr pair
#define mkpr make_pair
map<pair<int,int>,int>op;
inline void init(){
    scanf("%d%d",&n,&m);
    t.build(1,1,m);//以时间分治
    u.Reset(n);
    Inc(i,1,m)
    {
        int opt,x,y;
        scanf("%d%d%d",&opt,&x,&y);
        if(x>y)
            swap(x,y);//看样例
        if(opt==0)
        {
            e[op[mkpr(x,y)]=++cnte]=(Data){x,y};
            pre[cnte]=i;
        }else if(opt==1){//删除代表这条边只在之前的某个时刻到现在i（i-1）时间存在
            int idx=op[mkpr(x,y)];
            t.update(1,pre[idx],i,idx);//-1无所谓
            pre[idx]=-1;
        }else {
            q[++cntq]=(Data){x,y};
            t.LocQ(1,i,cntq);
        }
    }
    Inc(idx,1,m)if(~pre[idx])t.update(1,pre[idx],m,idx);
}
int main(){
    init();
    t.Stat(1);
    return 0;
}
