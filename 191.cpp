#include<bits/stdc++.h>

//easy + casework DP problem
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 30;

void Solve(){
	//dp[i][j] denotes the answer for the string of length i which ends with letter j
	vector<vector<ll>> dp(N, vector<ll>(4));
	//0 - O, 1 - A, 2 - L, 3 - AA
	ll res = 0;
	for(int j = -1; j < N; j++){
		for(int i = 0; i < N; i++){
			for(int k = 0; k < 4; k++)
				dp[i][k] = 0;
		}
		dp[0][0] = dp[0][1] = 1;
		if(j == 0){
			dp[0][0] = dp[0][1] = 0;
			dp[0][2] = 1;
		}
		for(int i = 1; i < N; i++){
			dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
			dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
			dp[i][3] = dp[i - 1][1];
			if(i == j){
				dp[i][0] = dp[i][1] = dp[i][3] = 0;
				dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][3];
			}
		}
		for(int i = 0; i < 4; i++){
			res += dp[N - 1][i];
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

