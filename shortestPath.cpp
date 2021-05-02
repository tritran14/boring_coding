#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'
#define all(x) (x).begin(),(x).end()
const int INF=1000000000+5;
const int N=2e5+5;
const ll oo=1e18+5;
const ll mod=1e9+7;

vector<pair<int,int>> v[N];

int dist[N];
int trace[N];
void dijkstra(int beg){
	for(int i=0;i<N;++i) trace[i]=-1;
	for(int i=0;i<N;++i) dist[i]=INF;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> PQ;
	dist[beg]=0;
	PQ.push({beg,0});
	while(!PQ.empty()){
		pair<int,int> u=PQ.top();
		PQ.pop();
		int now=u.first;
		int d=u.second;
		for(pair<int,int> next:v[now]){
			if(d+next.second<dist[next.first]){
				dist[next.first]=d+next.second;
				trace[next.first]=now;
				PQ.push({next.first,dist[next.first]});
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;++i){
		int x,y,w;
		cin>>x>>y>>w;
		--x,--y;
		v[x].push_back({y,w});
	}
	while(k--){
		int x,y,opt;
		cin>>opt>>x>>y;
		--x,--y;
		dijkstra(x);
		if(!opt) cout<<dist[y]<<endl;
		else{
			vector<int> path;
			path.push_back(y);
			while(trace[y]!=-1){
				path.push_back(trace[y]);
				y=trace[y];
			}
			reverse(all(path));
			cout<<(int)path.size()<<" ";
			for(int x:path) cout<<x+1<<" ";
			cout<<endl;
		}
	}
	return 0;
}
