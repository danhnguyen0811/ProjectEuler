#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;

const ll mod = 1234567891011;
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
bool MillerRabin(u64 n) {
    if(n < 2) return false;
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
long long multiply_modular (long long x, long long y){
    long long tmp = x;
    long long res = 0;
    while(y > 0) {
        if(y % 2) {
            res += tmp;
            res %= mod;
        }
        tmp = (2 * tmp) % mod;
        y /= 2;
    }
    return res;
}
vector<vector<long long>> matrix_multiply(vector<vector<long long>> a, vector<vector<long long>> b){
    int n = a.size();
    int m = b[0].size();
    vector<vector<long long>> res(n, vector<long long>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            long long sum = 0;
            for(int k = 0; k < b.size(); k++){
                sum += multiply_modular(a[i][k], b[k][j]);
                sum %= mod;
            }
            res[i][j] = sum;
        }
    }
    return res;
}
vector<vector<long long>> matrix_exp(vector<vector<long long>> C, long long n){
    vector<vector<long long>> res(C.size(), vector<long long> (C[0].size()));
    for(int i = 0; i < res.size(); i++)
        res[i][i] = 1;
    for(;n; n /= 2, C = matrix_multiply(C, C)){
        if(n % 2){
            res = matrix_multiply(res, C);
        }
    }
    return res;
}
void Solve(){
    vector<ll> primes;

    ll n = 1e14 + 1;
    while(primes.size() < int(1e5)){
        if(MillerRabin(n)) primes.pb(n);
        n++;
    }

    ll res = 0;
    vector<vector<ll>> C = {{1, 1}, {1, 0}};
    //vector<vector<ll>> tmp = matrix_exp(C, 3);
    //cout<<tmp[0][0]<<" "<<tmp[0][1]<<nl;
    //cout<<tmp[1][0]<<" "<<tmp[1][1]<<nl;
    for(auto x: primes){
        vector<vector<ll>> v = matrix_exp(C, x);
        res += v[0][1];
        res %= mod;
    }
    cout<<res<<nl;

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tests = 1;
    //cin>>tests;
    while(tests--){
        Solve();
    }
}
