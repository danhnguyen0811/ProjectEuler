#include<bits/stdc++.h>

//https://en.wikipedia.org/wiki/Pentagonal_number_theorem

using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;
//m*(3*m - 1)/2, m = 0, +-1, +-2, +-3, ....
const int N = 1e5;
const int MOD = 1e7;

void Solve(){
	vector<ll> f;
	f.push_back(0);
	for(ll i = 1;; i++){
		f.push_back(i * (3 * i - 1) / 2);
		f.push_back(i * (3 * i + 1) / 2);
		if(f.size() >= N) break;
	}
	vector<ll> res(N);
	res[0] = 1;
	res[1] = 1;
	res[2] = 2;
	for(int i = 3; i < N; i++){
		int turn = 0;
		for(int j = 1; j < N; j++){
			turn++;
			turn %= 4;
			if(i - f[j] < 0) break;
			if(turn == 1 || turn == 2){
				res[i] += res[i - f[j]];
			}
			else res[i] -= res[i - f[j]];
			res[i] %= MOD;
		}
	}
	int ans = -1;
	for(int i = 1; i < N; i++){
		//if(i < 25) cout<<res[i]<<nl;
		if(res[i] % 1000000 == 0){
			ans = i;
			break;
		}
	}
	cout<<ans<<nl;

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

