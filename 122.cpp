#include<bits/stdc++.h>

//https://wwwhomes.uni-bielefeld.de/achim/addition_chain.html
//construct the tree based on the source above
using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;
const int N = 200;

void Solve(){
    vector<int> res(N + 1);
    res[1] = 0;
    int cnt = 1;
    queue<vector<int>> q;
    q.push({1});
    int d = 0;
    while(cnt < N){
        queue<vector<int>> tmp;
        while(!q.empty() && cnt < N){
            vector<int> v = q.front();
            q.pop();
            int maxx = v.back();
            for(int i = v.size() - 1; i >= 0; i--){
                for(int j = i; j >= 0; j--){
                    int k = v[i] + v[j];
                    if(k > N) continue;
                    if(k <= maxx) break;
                    vector<int> tmp1 = v;
                    tmp1.pb(k);
                    tmp.push(tmp1);
                    if(res[k] == 0){
                        cnt++;
                        res[k] = d + 1;
                    }
                }
            }
        }
        q = tmp;
        d++;
    }
    int ans = 0;
    for(int i = 2; i <= N; i++){
        //cout<<i<<" "<<res[i]<<nl;
        ans += res[i];
    }
    cout<<ans<<nl;

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
