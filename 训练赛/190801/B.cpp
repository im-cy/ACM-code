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
#include <unordered_map>
#define rep(i,a,n) for(int i=a;i<n;++i)
#define per(i,a,n) for(int i=(n)-1;i>=a;--i)
#define foredge(u,i) for(int i=head[u];~i;i=l[i].nxt)
#define mem(a,x) memset(a,x,sizeof(a))
#define LOG(a) cout<<'#'<<a<<endl
void print_array(int *a,int n){printf("#");for(int i=0;i<n;i++) printf("%d%c",a[i],i==n-1?'\n':' ');}
// typedef __int128_t ll;
typedef long long ll;
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<int,int> pii;
const double EPS=1e-8;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int IINF=0x3f3f3f3f;
inline ll readll(){
	ll x(0),op(1);char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')op=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x*op;
}

ll M;
ll MOD;
ll phi(ll n){
	ll ans=n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ans=ans/i*(i-1);
			while(n%i==0) n/=i;
		}
	}
	if(n>1) ans=ans/n*(n-1);
	return ans;
}

mat mul(mat &A, mat &B){
	mat C(A.size(),vec(B[0].size()));
	rep(i,0,A.size()){
		rep(j,0,B[0].size()){
			rep(k,0,B.size()){
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%M;
			}
		}
	}
	return C;
}
mat mul(mat &A, mat &B,ll Mod){
	mat C(A.size(),vec(B[0].size()));
	rep(i,0,A.size()){
		rep(j,0,B[0].size()){
			rep(k,0,B.size()){
				C[i][j]=(C[i][j]+A[i][k]*B[k][j])%Mod;
			}
		}
	}
	return C;
}

//¾ØÕó¿ìËÙÃÝ
mat pow(mat A,int k){
	mat B(A.size(),vec(A.size()));
	rep(i,0,A.size()){
		B[i][i]=1;
	}
	while(k>0){
		if(k&1) B=mul(B,A);
		A=mul(A,A);
		k>>=1;
	}
	return B;
}
ll x0,x1,a,b;
// ll n;
char s[2000000];

mat getpow(){
	mat A(2,vec(2));
	A[0][0]=a;A[0][1]=b;A[1][0]=1;
	int n=strlen(s);
	mat ans(2,vec(2));
	ans[0][0]=ans[1][1]=1;
	per(i,0,n){
		if(i%100000==0) LOG(i);
		mat cur=pow(A,s[i]-'0');
		ans=mul(ans,cur);
		mat tmp=pow(A,10);
		A=tmp;
	}
	return ans;
}
ll solve(){
	mat A=getpow();
	mat B(2,vec(1));
	B[0][0]=x1;B[1][0]=x0;
	mat ans=mul(A,B);
	return ans[1][0]%MOD;
}

int main(){
	x0=readll(),x1=readll();a=readll(),b=readll();
	// scanf("%s",s);
	rep(i,0,1e6 ) s[i]='9';
	s[(int)1e6]='\0';
	MOD=readll();
	// M=phi(MOD);
	// LOG(M);
	// n=readn();
	M=MOD;
	// LOG(n);
	ll ans=solve();
	cout<<(long long)ans<<endl;
	return 0;
}
/*
1315 521 20185 5452831
*/
