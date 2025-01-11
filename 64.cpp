#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;

const int N = 10000;

void Solve(){
    int res = 0;
    for(int i = 2; i <= N; i++){
        int k = sqrt(i);
        if(k * k == i) continue;
        vector<int> v;
        int a = i, b = 1;
        while(v.size() < 500){
            int last = (long double)b / (sqrtl((long double)a)
            - (long double)k);

            v.pb(last);
            int gcd = __gcd(b, a - k * k);
            b /= gcd;
            int new_b = (a - k * k) / gcd;
            int new_a = b * b * a;
            int new_k = last * new_b - b * k;
            b = new_b;
            a = new_a;
            k = new_k;
        }
        for(int period = 1; period <= 250; period++){
            bool valid = true;
            for(int j = 1; j < 500; j++){
                if(j - period >= 0 && v[j - period] != v[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                if(period % 2) res++;
                break;
            }
        }
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
