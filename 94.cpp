#include<bits/stdc++.h>

//simply brute-force i guess, this problem does not deserve 35% difficulty

using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 1e9;

bool isPossible(ll a, ll b){
	ll k = a * a - (b / 2) * (b / 2);
	ll tmp = sqrt(k);
	if(tmp * tmp == k) return true;
	return false;
}
void Solve(){
	ll res = 0;
	for(ll a = 3; a * 3 < N; a += 2){
		if(isPossible(a, a - 1)) res += a * 3 - 1;
		if(isPossible(a, a + 1)) res += a * 3 + 1;
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

