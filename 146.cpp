//--this-template-is-from-cp-algorithms-------
#include <bits/stdc++.h>

//find all the numbers in which n^2 + 1,...n^2 + 27 are all primes
//then subtract the numbers in which one of n^2 + 5, n ^ 2 + 11,...
//is prime

using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}
void Solve(){
	ll res = 0;
	ll ans = 821107610;
	int n;
	cin>>n;
	vector<ll> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	for(auto x: v){
		bool valid = true;
		for(ll i: {5, 11, 15, 17, 19, 21, 23, 25}){
			ll k = x * x + i;
			if(MillerRabin(k)) valid = false;
		}
		if(!valid) ans -= x;
	}
	cout<<ans<<nl;

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	Solve();
}
