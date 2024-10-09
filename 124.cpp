#pragma GCC optimize("O3")
#include<bits/stdc++.h>

//easy problem, just brute force
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 1e5;

vector<int> g[N + 1];

void Solve(){
	vector<pair<int, int>> v;
	vector<bool> isPrime(N, true);
	for(int i = 2; i * i < N; i++){
		for(int j = i + i; j < N; j += i){
			isPrime[j] = false;
		}
	}
	g[1].push_back(1);
	for(int i = 2; i < N; i++){
		if(!isPrime[i]) continue;
		for(int j = i; j <= N; j += i){
			g[j].push_back(i);
		}
	}
	for(int i = 1; i <= N; i++){
		ll k = 1;
		for(auto x: g[i])
			k *= (ll)x;
		v.push_back({k, i});
	}
	sort(v.begin(), v.end());
	cout<<v[9999].se<<nl;

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}

