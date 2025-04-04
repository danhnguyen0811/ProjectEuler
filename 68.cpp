#include<bits/stdc++.h>

// classic backtracking problem
using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;

vector<int> v;
string res = "";

void get(){
    vector<int> leaves;
    for(int i = 1; i <= 10; i++){
        bool found = false;
        for(auto x: v){
            if(x == i) found = true;
        }
        if(!found) leaves.push_back(i);
    }
    v.push_back(v[0]);
    int min_leave = 10;
    for(auto x: leaves){
        min_leave = min(min_leave, x);
    }
    for(int x: leaves){
        vector<string> s;
        int sum = v[0] + v[1] + x;
        set<int> avai;
        string t = "";
        t += to_string(x);
        t += to_string(v[0]);
        t += to_string(v[1]);
        string ans = "";
        s.push_back(t);
        for(auto y: leaves){
            if(y != x) avai.insert(y);
        }
        for(int i = 1; i < 5; i++){
            int need = sum - v[i] - v[i + 1];
            if(avai.find(need) == avai.end()) break;
            t = "";
            t += to_string(need);
            t += to_string(v[i]);
            t += to_string(v[i + 1]);
            avai.erase(need);
            s.push_back(t);
        }
        if(s.size() == 5){
            int idx = 0;
            for(int i = 0; i < s.size(); i++){
                int cur = s[i][0] - '0';
                if(cur == min_leave) idx = i;
            }
            ans += s[idx];
            for(int i = idx + 1; i < s.size(); i++){
                ans += s[i];
            }
            for(int i = 0; i < idx; i++){
                ans += s[i];
            }
            res = max(res, ans);
        }
    }
    v.pop_back();
}
void backtrack(){
    if(v.size() == 5){
        get();
        return;
    }
    for(int i = 1; i <= 9; i++){
        bool found = false;
        for(auto x: v){
            if(x == i) found = true;
        }
        if(found) continue;
        v.push_back(i);
        backtrack();
        v.pop_back();
    }
}
void Solve(){
    backtrack();
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
