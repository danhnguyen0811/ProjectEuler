#include<bits/stdc++.h>

//ez problem
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 51;
const int P = 11243247;
vector<ll> g[N];

void Solve(){
	vector<bool> isPrime(P + 1, true);
	for(int i = 2; i * i <= P; i++){
		for(int j = i * i; j <= P; j += i)
			isPrime[j] = false;
	}
	vector<int> primes;
	for(int i = 2; i <= P; i++){
		if(isPrime[i]) primes.push_back(i);
	}
	g[0].push_back(1);
	ll maxx = 0;
	set<ll> s;
	s.insert(1);
	for(int i = 1; i < N; i++){
		int idx = 0;
		while(idx <= g[i - 1].size()){
			if(idx == 0 || idx == g[i - 1].size()) g[i].push_back(1);
			else{
				ll x = g[i - 1][idx - 1] + g[i - 1][idx];
				g[i].push_back(x);
				maxx = max(maxx, x);
				s.insert(x);
			}
			idx++;
		}
	}
	ll res = 0;
	while(!s.empty()){
		ll n = *s.begin();
		s.erase(s.begin());
		bool isValid = true;
		for(auto x: primes){
			if(x * x > n) break;
			if((n % ((ll)x * x)) == 0) isValid = false;
		}
		if(isValid) res += n;
	}
	cout<<res<<nl;

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

