#include<bits/stdc++.h>

//backtracking to generate all the permutation, then using recursion to brute-force the answer
using namespace std;

#define nl '\n'

vector<char> c = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

vector<string> v;
string s = "";

bool found(char target){
	for(char i: s){
		if(i == target) return true;
	}
	return false;
}
void backtrack(){
	if(s.size() == 9){
		v.push_back(s);
		return;
	}
	for(int i = 0; i < 9; i++){
		if(found(c[i])) continue;
		s += c[i];
		backtrack();
		string t = "";
		for(int j = 0; j < s.size() - 1; j++)
			t += s[j];
		s = t;
	}
}
int res = 0;
bool isPrime(int n){
	if(n == 1) return false;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}
void dp(int n, string a){
	int f = stoi(a);
	if(isPrime(f) && f > n) res++;
	string b = "";
	for(char ch: a){
		b += ch;
		int k = stoi(b);
		if(isPrime(k) && k > n){
			string tmp = "";
			for(int i = b.size(); i < a.size(); i++)
				tmp += a[i];
			//cout<<a<<" "<<k<<" "<<tmp<<nl;
			if(tmp.size()) dp(k, tmp);
		}
	}
}
void Solve(){
	backtrack();
	for(string a: v){
		dp(0, a);
	}
	cout<<res<<nl;
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	//cin>>T;
	while(T--){
		Solve();
	}
}
