//https://en.wikipedia.org/wiki/Pythagorean_triple
//this problem can be solved using the recourse above
#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 1e6 + 5e5 + 1;
//const int N = 1e4 + 1;

vector<int> cnt(N);

void Solve(){
	set<pair<int, int>> s;
	for(ll i = 1; i < N; i++){
		for(ll j = i + 1; i * i + j * j < N; j++){
			int a = j * j - i * i;
			int b = 2 * i * j;
			int c = i * i + j * j;
			int k = 1;
			while(a * k + b * k + c * k < N){
				if(s.find({a * k, b * k}) == s.end()){
					s.insert({a * k, b * k});
					s.insert({b * k, a * k});
					cnt[a * k + b * k + c * k]++;
				}
				k++;
			}
		}
	}
	ll res = 0;
	for(int i = 0; i < N; i++){
		//cout<<i<<" "<<cnt[i]<<nl;
		if(cnt[i] == 1){
			//cout<<i<<nl;
			res++;
		}
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
