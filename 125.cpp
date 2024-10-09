#pragma GCC optimize("O3")
#include<bits/stdc++.h>

//easy problem, the only trap is there might be duplicated numbers
using namespace std;

#define nl '\n'
#define fi first
#define se second

typedef long long ll;

vector<int> v;

bool isPalindrome(int n){
	string s = to_string(n);
	string t = "";
	for(int i = s.size() - 1; i >= 0; i--)
		t += s[i];
	return s == t;
}
void Solve(){
	int cur = 1;
	while(cur < 1e4){
		v.push_back(cur * cur);
		cur++;
	}
	int n = v.size();
	ll res = 0;
	set<int> s;
	for(int i = 0; i < n - 1; i++){
		ll sum = v[i];
		for(int j = i + 1; j < n; j++){
			sum += v[j];
			if(sum >= 1e8) break;
			if(isPalindrome(sum)){
				s.insert(sum);
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
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}
