#include<bits/stdc++.h>

// X can be very large so we need to use __int128
// this is the classic Pell's equation problem
using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;

const int N = 1000;

void Solve(){
    __int128 max_x = 0, res = 0;
    for(int i = 2; i <= N; i++){
        int k = sqrt(i);
        if(k * k == i) continue;
        int a = i, b = 1;
        __int128 p0 = 1, p1 = k;
        __int128 q0 = 0, q1 = 1;
        while(true){
            int last = (long double)b / (sqrtl((long double)a)
            - (long double)k);
            int gcd = __gcd(b, a - k * k);
            b /= gcd;
            int new_b = (a - k * k) / gcd;
            int new_a = b * b * a;
            int new_k = last * new_b - b * k;
            b = new_b;
            a = new_a;
            k = new_k;
            __int128 tmp_p = p1, tmp_q = q1;
            p1 = (__int128)last * p1 + p0;
            q1 = (__int128)last * q1 + q0;
            p0 = tmp_p;
            q0 = tmp_q;
            if(p1 * p1 - q1 * q1 * i == 1){
                if(max_x < p1){
                    //cout<<i<<" "<<(__int128)p1<<" "<<(__int128)q1<<nl;
                    max_x = p1;
                    res = i;
                }
                break;
            }
        }
    }
    cout<<(int)res<<nl;

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
