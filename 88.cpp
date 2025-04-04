#include<bits/stdc++.h>

//phew, didn't expect it run this fast
using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;

const int N = 12000;
vector<int> d[N * 2 + 1];
int sum = 0;
bool ok = false;
int K, target;

void dfs(int n, int cnt){
    //cout<<"??? "<<n<<" "<<cnt<<" "<<sum<<nl;
    if(ok || sum > target || cnt > K) return;
    if(n == 1 || cnt == K){
        int remain = K - cnt;
        sum += remain;
        //cout<<n<<" "<<cnt<<" "<<remain<<" "<<sum<<nl;
        if(sum == target){
            ok = true;
            //cout<<n<<" "<<cnt<<" "<<remain<<" "<<sum<<nl;
        }
        sum -= remain;
        return;
    }
    for(auto x: d[n]){
        sum += x;
        dfs(n / x, cnt + 1);
        sum -= x;
    }
}
void Solve(){
    int res = 0;
    for(int i = 1; i <= N * 2; i++){
        for(int j = i; j > 1; j--){
            if(i % j == 0) d[i].pb(j);
        }
    }
    set<int> s;
    for(int k = 2; k <= N; k++){
        //the upper bound for minimal product-sum is 2 * k
        //and the lower bound is k of course
        K = k;
        ok = false;
        for(int n = k; n <= 2 * k; n++){
            target = n;
            sum = 0;
            dfs(n, 0);
            if(ok){
                s.insert(n);
                break;
            }
        }
    }
    while(!s.empty()){
        res += *s.begin();
        s.erase(s.begin());
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
