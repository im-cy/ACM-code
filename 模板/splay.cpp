#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int MAXN=1000007;
class Splay
{
	public:
		Splay(int n,int *num)
		{
			for(int i = 1 ; i <= n ; i ++)
				insert(num[i]);
		}
		void clear(int x)
		{
		    f[x] = cnt[x] = ch[x][0] = ch[x][1] = size[x] = key[x] = 0;
		}
		bool get(int x)
		{
		    return ch[f[x]][1] == x;
		}
		void pushup(int x)
		{
		    if(x)
		    {
		        size[x] = cnt[x];
		        if(ch[x][0])
					size[x] += size[ch[x][0]];
		        if(ch[x][1])
					size[x] += size[ch[x][1]];
		    }
		}
		void rotate(int x)
		{
		    int old = f[x] , oldf = f[old] , which = get(x);
		    ch[old][which] = ch[x][which^1];
			f[ch[old][which]] = old;
		    ch[x][which^1] = old;
			f[old] = x;
		    f[x] = oldf;
		    if(oldf)
				ch[oldf][ch[oldf][1] == old] = x;
		    pushup(old);
			pushup(x);
		}
		void splay(int x)
		{
		    for(int fa; fa=f[x]; rotate(x))
		        if(f[fa])
		        	rotate((get(x) == get(fa))?fa:x);
		    rt = x;
		}
		void insert(int x)
		{
		    if(rt==0)
		    {
		        sz++; key[sz]=x; rt=sz;
		        cnt[sz]=size[sz]=1;
		        f[sz]=ch[sz][0]=ch[sz][1]=0;
		        return;
		    }
		    int now=rt,fa=0;
		    while(1)
		    {
		        if(x==key[now])
		        {
		            cnt[now]++; pushup(now); pushup(fa); splay(now); return;
		        }
		        fa=now; now=ch[now][key[now]<x];
		        if(now==0)
		        {
		            sz++; 
		            size[sz]=cnt[sz]=1;
		            ch[sz][0]=ch[sz][1]=0;
		            ch[fa][x>key[fa]]=sz;
		            f[sz]=fa; 
		            key[sz]=x;
		            pushup(fa); splay(sz); return;
		        }
		    }
		}
		int rnk(int x)
		{
		    int now=rt,ans=0;
		    while(1)
		    {
		        if(x < key[now])
					now = ch[now][0];
		        else
		        {
		            ans += size[ch[now][0]];
		            if(x == key[now])
		            {
		                splay(now);
						return ans + 1;
		            }
		            ans += cnt[now];
		            now = ch[now][1];
		        }
		    }
		}
		int kth(int x)
		{
		    int now = rt;
		    while(1)
		    {
		        if(ch[now][0] && x <= size[ch[now][0]])
		            now=ch[now][0];
		        else
		        {
		            int temp = size[ch[now][0]] + cnt[now];
		            if(x <= temp)
		                return key[now];
		            x -= temp;
					now = ch[now][1];
		        }
		    }
		}
		int pre()
		{
		    int now = ch[rt][0];
		    while(ch[now][1])
				now = ch[now][1];
		    return now;
		}
		int next()
		{
		    int now = ch[rt][1];
		    while(ch[now][0])
				now = ch[now][0];
		    return now;
		}
		int findnxt(int k)
		{
			insert(k); 
			int ans = key[next()];
			del(k);
			return ans;
		}
		int findpre(int k)
		{
			insert(k); 
			int ans = key[pre()];
			del(k);
			return ans;
		}
		void del(int x)
		{
		    rnk(x);
		    if(cnt[rt]>1) {cnt[rt]--; pushup(rt); return;}
		    if(!ch[rt][0] && !ch[rt][1]) {clear(rt); rt=0; return;}
		    if(!ch[rt][0])
			{
		        int oldrt=rt;
				rt=ch[rt][1];
				f[rt]=0;
				clear(oldrt);
				return;
		    }
		    else if(!ch[rt][1])
			{
		        int oldrt=rt;
				rt=ch[rt][0];
				f[rt]=0;
				clear(oldrt);
				return;
		    }
		    int oldrt=rt;
			int leftbig=pre();
		    splay(leftbig);
		    ch[rt][1] = ch[oldrt][1];
		    f[ch[oldrt][1]] = rt;
		    clear(oldrt);
		    pushup(rt);
		}
	private:
		int f[MAXN],cnt[MAXN],ch[MAXN][2],size[MAXN],key[MAXN],sz,rt;
};
int num[MAXN];
int n;
int main()
{
	Splay *tree = new Splay(0,num);
	
	return 0;
}

