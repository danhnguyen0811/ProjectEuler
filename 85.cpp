 
#include<bits/stdc++.h>

//https://math.stackexchange.com/questions/1656686/how-many-rectangles-can-be-observed-in-the-grid

using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 2e3;

void Solve(){
	ll ans = 0;
	ll diff = INT_MAX;
	for(int i = 1; i < N; i++){
		for(int j = 1; j < N; j++){
			ll k = (ll)(i + 1) * i * (j + 1) * j / 4;
			if(abs(k - 2000000) < diff){
				diff = abs(k - 2000000);
				ans = (ll)i * j;
			}
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
