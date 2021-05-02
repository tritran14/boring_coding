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

const int INF=1000000000+5;
const int N=2e5+5;
const int M=30;
const ll oo=LLONG_MAX;
const int mod=1e9+7;

vector<pair<int,int>> v[N];

int dist[N];
void dijkstra(int beg){
	for(int i=0;i<N;++i) dist[i]=INF;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
	dist[beg]=0;
	PQ.push({0,beg});
	while(!PQ.empty()){
		pair<int,int> u=PQ.top();
		PQ.pop();
		int now=u.second;
		int d=u.first;
		if(d!=dist[now]) continue;
		for(pair<int,int> next:v[now]){
			int vv=next.first;
			int uv=next.second;
			if(dist[vv]>d+uv){
				dist[vv]=d+uv;
				PQ.push({dist[vv],vv});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,s,t;
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int x,y,w;
		cin>>x>>y>>w;
		--x,--y;
		v[x].push_back({y,w});
	}
	cin>>s>>t;
	--s,--t;
	dijkstra(s);
	int ans=dist[t];
	if(ans==INF) ans=-1;
	cout<<ans;
	return 0;
}
