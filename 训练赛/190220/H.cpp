#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include <sstream>
#define ll long long
using namespace std;
struct point {
	ll sz;
	string nm;
	bool is_leaf;
	bool is_open;
} tree[20100];
int ptot = 1, tot = 1, l[20100];
int hed[20100], nxt[20100], chudu[20010];
void build(int f, int t) {
	l[tot] = t;
	nxt[tot] = hed[f];
	hed[f] = tot ++;
}
int n;
int findstring(string x) {
	for(int i = 1 ; i <= ptot ; i ++)
		if(tree[i].nm == x)
			return i;
	return -1;
}
ll k;
struct ans{
	string id;
	string msg;
	void set(string idd,string msgg){
		id=idd;msg=msgg;
	}
	friend bool operator<(ans a,ans b){
		return a.id < b.id;
	}
}anss[20100];
int ansn=0;
bool vis[20010];
string tmp;
string m_to_string(ll x){
	std::stringstream ss;
	ss<<x;
	string str;
	ss>>str;
	return str;
}

void dfs(int u, int f) {
	vis[u] = 1;
	if(!tree[u].is_leaf) {
		if(!tree[u].is_open) {
			anss[ansn++].set(tree[u].nm + "/ ","+ " + tree[u].nm + "/ " + m_to_string(tree[u].sz));
			return ;
		} else
			tmp= "- ";
	} else {
		tmp= "  ";
	}
	anss[ansn++].set(tree[u].nm,tmp+tree[u].nm + "/ " + m_to_string(tree[u].sz));
	// cout << tree[u].nm << "/ " << tree[u].sz << endl;
	for(int i = hed[u] ; i ; i = nxt[i]) {
		if(!vis[l[i]]) {
			dfs(l[i], u);
		}
	}
}
int main() {
	scanf("%d", &n);
	tree[1].nm = "";
	for(int i = 1 ; i <= n ; i ++) {
		string in;
		ll tmpsz;
		in.clear();
		cin >> in >> tmpsz;
		int inl = in.length();
		int last = 0;
		int lastpoint = 1;
		int stringtot = 0;
		for(int j = 1 ; j < inl ; j ++) {
			if(in[j] == '/') {
				stringtot ++;
				string newpoint = in.substr(0, j);
				int res = findstring(newpoint);
				if(res != -1) {
					build(lastpoint,res);
					lastpoint = res;
					tree[lastpoint].sz += tmpsz;
				} else {
					ptot ++;
					tree[ptot].nm = newpoint;
					tree[ptot].sz += tmpsz;
					chudu[lastpoint] ++;
					build(lastpoint, ptot);
					//			build(ptot,lastpoint);
					//			cout << "build " << tree[lastpoint].nm << " "
					//			     << tree[ptot].nm << endl;
					lastpoint = ptot;
				}
				last = j;
			}
		}
		if(stringtot == 0)
			tree[1].sz += tmpsz;
	}
	scanf("%d", &k);
	for(int i = 1 ; i <= ptot ; i ++) {
		for(int j = hed[i] ; j ; j = nxt[j]) {
			if(tree[l[j]].sz >= k) {
				//	cout << tree[i].nm << " " << tree[l[j]].nm << endl;
				tree[i].is_open = 1;
				break;
			}
		}
	}
	for(int i = 1 ; i <= ptot ; i ++)
		if(!chudu[i])
			tree[i].is_leaf = 1;
	for(int i = hed[1] ; i ; i = nxt[i])
	{
		if(!vis[l[i]])
		{
			vis[l[i]] = 1;
			tree[1].sz += tree[l[i]].sz;
		}
	}
	memset(vis,0,sizeof(vis));
	dfs(1, 0);
	sort(anss,anss+ansn);
	for(int i=0;i<ansn;i++){
		cout<<anss[i].msg<<endl;
		// printf("%s\n", );
	}
	return 0;
}
/*
9
/cerc/documents/rules.pdf 4000
/cerc/problems/b/kale.cc 100
/cerc/problems/b/testdata/out 4
/cerc/problems/b/testdata/in 15
/cerc/problems/a/zuza.cc 5000
/cerc/problems/a/testdata/out 8
/cerc/problems/a/luka.cc 500
/cerc/problems/a/testdata/in 1000000
/sys/kernel/notes 100
10000
*/

