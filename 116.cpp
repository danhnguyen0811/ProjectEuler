#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

//the length of the measuring
const int N = 50;

void Solve(){
	//dp[i] denotes the answer til position i
	vector<vector<ll>> dp2(N + 1, vector<ll> (2));
	vector<vector<ll>> dp3(N + 1, vector<ll> (2));
	vector<vector<ll>> dp4(N + 1, vector<ll> (2));
	for(int i = 0; i <= N; i++)
		dp2[i][0] = dp3[i][0] = dp4[i][0] = 1;
	for(int i = 2; i <= N; i++){
		dp2[i][1] = dp2[i - 2][1] + dp2[i - 2][0];
		dp2[i][0] = dp2[i - 1][1] + dp2[i - 1][0];
		if(i >= 3){
			dp3[i][1] = dp3[i - 3][1] + dp3[i - 3][0];
			dp3[i][0] = dp3[i - 1][1] + dp3[i - 1][0];
		}
		if(i >= 4){
			dp4[i][1] = dp4[i - 4][1] + dp4[i - 4][0];
			dp4[i][0] = dp4[i - 1][1] + dp4[i - 1][0];
		}
	}
	cout<<dp2[N][0] + dp2[N][1] + dp3[N][0] + dp3[N][1] + dp4[N][0] + dp4[N][1] - 3<<nl;

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

