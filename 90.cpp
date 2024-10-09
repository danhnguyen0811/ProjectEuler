#include <bits/stdc++.h>

//have no idea why this problem has 40% difficulty, simple backtrack + bruteforce would do the work
using namespace std;

vector<char> a = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
vector<vector<char>> v;
vector<char> tmp;

void backtrack(int st){
	if(tmp.size() == 6){
		v.push_back(tmp);
		return;
	}
	for(int i = st; i < 10; i++){
		tmp.push_back(a[i]);
		backtrack(i + 1);
		tmp.pop_back();
	}
}
int main() {
	backtrack(0);
	vector<string> target = {"01", "04", "09", "16", "25", "36", "49", "64", "81"};
	int res = 0;
	for(int i = 0; i < 210; i++){
		for(int j = i + 1; j < 210; j++){
			bool ok = true;
			set<char> s1, s2;
			for(char c: v[i]){
				s1.insert(c);
				if(c == '6') s1.insert('9');
				if(c == '9') s1.insert('6');
			}
			for(char c: v[j]){
				s2.insert(c);
				if(c == '6') s2.insert('9');
				if(c == '9') s2.insert('6');
			}
			for(string s: target){
				char c1 = s[0];
				char c2 = s[1];
				bool valid = false;
				if(s1.find(c1) != s1.end() && s2.find(c2) != s2.end()) valid = true;
				if(s1.find(c2) != s1.end() && s2.find(c1) != s2.end()) valid = true;
				if(!valid) ok = false;
			}
			if(ok) res++;
		}
	}
	cout<<res<<endl;

	return 0;
}
