#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 100;

void Solve(){
	vector<vector<ll>> dp1(N, vector<ll> (10)); //increasing
	vector<vector<ll>> dp2(N, vector<ll> (10)); //decreasing
	for(int i = 0; i < 10; i++){
		dp1[0][i] = dp2[0][i] = 1;
	}
	for(int i = 1; i < N; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k <= j; k++)
				dp1[i][j] += dp1[i - 1][k];
			for(int k = 9; k >= j; k--)
				dp2[i][j] += dp2[i - 1][k];
		}
	}
	ll res = 0;
	for(int i = 1; i < 10; i++)
		res += dp1[N - 1][i];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 10; j++)
			//cout<<i<<" "<<j<<" "<<dp2[i][j]<<nl;
			res += dp2[i][j];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 10; j++)
			res--;
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

