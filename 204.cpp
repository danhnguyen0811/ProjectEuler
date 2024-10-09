#include<bits/stdc++.h>

//surprisingly the answer is correct, i thought i was too small
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

const int N = 1e9;
vector<bool> isPrime(N, true);
vector<bool> check(N);

void Solve(){
	for(int i = 2; i * i < N; i++){
		for(int j = i * i; j < N; j += i)
			isPrime[j] = false;
	}
	vector<int> primes;
	for(int i = 101; i < N; i++){
		if(isPrime[i]) primes.push_back(i);
	}

	for(auto x: primes){
		int k = x;
		while(x < N){
			check[x] = true;
			x += k;
		}
	}
	int cnt = 0;
	for(int i = 101; i < N; i++)
		if(check[i]) cnt++;
	cout<<N - cnt<<nl;

	//answer should be N - s.size()
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

