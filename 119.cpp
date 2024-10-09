#pragma GCC optimize("O3")
#include<bits/stdc++.h>

//easy one, it's bruteforcable
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 161;

void Solve(){
	vector<pair<ll, int>> v;
	for(ll i = 2; i <= N; i++){
		ll k = i;
		while(k * i < 1e16){
			k *= i;
			string s = to_string(k);
			int sum = 0;
			for(char c: s){
				sum += c - '0';
			}
			if(sum == i) v.push_back({k, i});
		}
	}
	sort(v.begin(), v.end());
	cout<<v[29].fi<<" "<<v[29].se<<nl;

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

