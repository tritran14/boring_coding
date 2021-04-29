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
const int N=3e5+5;
const int M=30;
const ll oo=LLONG_MAX;
const int mod=1e9+7;

//~ #title
//~ print minimum number operations using transform a to b
//~ first is *2
//~ second is -1

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a,b;
	cin>>a>>b;
	if(a>=b){
		return cout<<a-b,0;
	}
	int pow2=1;
	int ans=INF;
	for(int bit=1;bit<31;++bit){
		pow2*=2;
		if(1ll*pow2*a<b) continue;
		ll mask=1ll*pow2*a-b;
		int cur=bit+ __builtin_popcount(mask);
		//~ trace(bit,mask,__builtin_popcount(mask),mask,pow2);
		ans=min(ans,cur);
	}
	cout<<ans;
	return 0;
}
