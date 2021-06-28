typedef long long ll;
const int mod=1e9+7;
const int maxn=100005;
vector<int> v[maxn];
int dp[maxn];
int sizee[maxn];
int fac[maxn],ifac[maxn];

int mul(int a,int b){
    return 1ll*a*b%mod;
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

struct bino{
    bino(){
		fac[0]=fac[1]=1;
		ifac[0]=ifac[1]=inv(1);
		for(int i=2;i<maxn;++i){
			fac[i]=mul(fac[i-1],i);
			ifac[i]=inv(fac[i]);
		}
    }
} binoo;

class Solution {
public:
	
	void dfs(int u,int par){
		sizee[u]=1;
		dp[u]=1;
		for(int x:v[u]){
			if(x==par) continue;
			dfs(x,u);
			sizee[u]+=sizee[x];
			dp[u]=mul(dp[u],dp[x]);
            dp[u]=mul(dp[u],ifac[sizee[x]]);
		}
		dp[u]=mul(dp[u],fac[sizee[u]-1]);
	}
	
    int waysToBuildRooms(vector<int>& p) {
		//~ return -142;
        int n=(int)p.size();
        for(int i=0;i<n;++i) v[i].clear();
        for(int i=0;i<n;++i){
			if(p[i]>=0){
				//~ trace(p[i],i);
				v[p[i]].push_back(i);
				v[i].push_back(p[i]);
			}
		}
		//~ return -142;
		dfs(0,-1);
		return dp[0];
    }
};
