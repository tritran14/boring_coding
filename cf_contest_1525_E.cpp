#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define trace(...) debug(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void debug(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void debug(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " | ";
  debug(comma + 1, args...);
}

const int INF=2e5+5;
const int N=5e4+5;
const int M=30;
const ll oo=LLONG_MAX;
const int mod=998244353;

inline void check_ONLINE_JUDGE(){
	#ifndef ONLINE_JUDGE 
	freopen("INP.txt","r",stdin);
	freopen("OUT.txt","w",stdout);
	#endif
}

int fac[N];

int mul(int a,int b){
	return 1ll*a*b%mod;
}

void init(){
	fac[0]=fac[1]=1;
	for(int i=2;i<N;++i) fac[i]=mul(fac[i-1],i);
}


int poww(int a,int b){
	int r=1;
	while(b){
		if(b&1) r=mul(r,a);
		a=mul(a,a);
		b>>=1;
	}
	return r;
}

int inv(int x){
	return poww(x,mod-2);
}

void add_self(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}

void solve(){
	init();
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m));
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j) cin>>a[i][j];
	}
	int denominator=inv(fac[n]);
	// trace(denominator);
	int ans=0;
	for(int j=0;j<m;++j){
		vector<int> can;
		for(int i=0;i<n;++i){
			if(a[i][j]>=n+1) continue;
			can.push_back(n-a[i][j]+1);
		}
		// trace((int)can.size());
		if((int)can.size()==0) continue;
		auto cmp=[&](int a,int b){
			return a>b;
		};
		sort(all(can),cmp);
		int cur=1;
		int used=0;
		for(int x:can){
			cur=mul(cur,max(0,n-x-used));
			++used;
		}
		// no one city can reach to sthis point
		cur=mul(cur,fac[n-(int)can.size()]);
		cur=(fac[n]-cur+mod)%mod;
		// trace(cur);
		add_self(ans,cur);
	}
	ans=mul(ans,denominator);
	cout<<ans<<endl;
}

int main(){
	check_ONLINE_JUDGE();
	ios::sync_with_stdio(0); cin.tie(0);
	int t=1;
	// cin>>t;
	while(t--) solve();
	return 0;
}
