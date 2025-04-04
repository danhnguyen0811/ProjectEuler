#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;

const int M = 2000;

void Solve(){
    int res = INT_MAX;
    int low = 1000, high = 2000;
    while(low <= high){
        int M = (low + high) >> 1;
        int cnt = 0;
        for(int x = 1; x <= M; x++){
            for(int y = x; y <= M; y++){
                for(int z = y; z <= M; z++){
                    ll d = z * z + (ll)(x + y) * (x + y);
                    ll k = sqrtl(d);
                    if(k * k == d) cnt++;
                }
            }
        }
        if(cnt > 1000000){
            res = min(res, M);
            high = M - 1;
        }
        else low = M + 1;
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
