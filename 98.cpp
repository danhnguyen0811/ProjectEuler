#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

// luckily the result is not that large, otherwise, my program would run forever
typedef long long ll;

vector<char> v;
vector<vector<char>> d;
vector<char> digits;

void backtrack(){
    if(digits.size() == v.size()){
        d.push_back(digits);
        return;
    }
    for(char c = '0'; c <= '9'; c++){
        bool found = false;
        for(auto x: digits){
            if(x == c) found = true;
        }
        if(found || (c == '0' && digits.size() == 0)) continue;
        digits.push_back(c);
        backtrack();
        digits.pop_back();
    }
}
void permute(string &s, int left, int right, vector<string> &result){
    if (left == right){
        result.push_back(s);
        return;
    }
    for (int i = left; i <= right; i++){
        swap(s[left], s[i]);
        permute(s, left + 1, right, result);
        swap(s[left], s[i]);
    }
}
void Solve(){
    ll res = 0;
    set<string> s;
    string t;
    cin>>t;
    int i = 1;
    while(i < t.size()){
        string w = "";
        while(i < t.size() && t[i] != '"' && t[i] != ','){
            w += t[i++];
        }
        // current result is 18769
        if(w.size() < 9 && w.size() >= 6) s.insert(w);
        i += 3;
    }
    while(!s.empty()){
        v.clear();
        d.clear();
        digits.clear();
        string a = *s.begin();
        s.erase(s.begin());
        for(char c: a){
            bool found = false;
            for(auto x: v){
                if(x == c) found = true;
            }
            if(!found) v.push_back(c);
        }
        backtrack();
        vector<string> p;
        permute(a, 0, a.size() - 1, p);
        for(auto x: d){
            string num = a;
            map<char, char> mm;
            for(int i = 0; i < x.size(); i++){
                mm[v[i]] = x[i];
            }
            for(int i = 0; i < num.size(); i++){
                num[i] = mm[num[i]];
            }
            ll k = stoll(num);
            ll sq = sqrtl(k);
            if(sq * sq != k) continue;
            for(string t: p){
                if(s.find(t) == s.end()) continue;
                string cur = t;
                for(int i = 0; i < t.size(); i++){
                    cur[i] = mm[cur[i]];
                }
                if(cur[0] == '0') continue;
                ll kk = stoll(cur);
                sq = sqrt(kk);
                if(sq * sq != kk) continue;
                if(res < k || res < kk){
                    cout<<res<<" "<<k<<" "<<kk<<" "<<a<<nl;
                    res = max({res, k, kk});
                }
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
