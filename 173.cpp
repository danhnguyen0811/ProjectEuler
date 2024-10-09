#pragma GCC optimize("O3")
#include<bits/stdc++.h>

//it's not hard to come up with the idea
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const ll N = 1e6;

void Solve(){
	ll res = 0;
	for(ll i = 1; (i + 1) * 4 <= N; i++){
		ll x = N + i * i;
		x = sqrt(x);
		if(i % 2){
			if(x % 2 == 0) x--;
			res += (x - i) / 2;
		}
		else{
			if(x % 2) x--;
			res += (x - i) / 2;
		}
		//cout<<i<<" "<<x<<" "<<res<<nl;
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

