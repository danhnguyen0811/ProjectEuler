#include<bits/stdc++.h>

using namespace std;

void Solve(){
	string s;
	int res = 0;
	while(cin>>s){
		int i = 0;
		vector<int> tmp;
		while(i < s.size()){
			int sign = 1;
			if(s[i] == '-'){
				sign = -1;
				i++;
			}
			string t = "";
			while(i < s.size() && s[i] != ','){
				t += s[i];
				i++;
			}
			if(i < s.size() && s[i] == ',') i++;
			tmp.push_back(stoi(t) * sign);
		}

		double total_area = (double)(tmp[0] * (tmp[3] - tmp[5]) + tmp[2] * (tmp[5] - tmp[1])
		 + tmp[4] * (tmp[1] - tmp[3])) / 2;
		double area1 = (double)(tmp[2] * tmp[5] - tmp[4] * tmp[3]) / 2;
		double area2 = (double)(tmp[0] * (-tmp[5]) + tmp[4] * tmp[1]) / 2;
		double area3 = (double)(tmp[0] * tmp[3] - tmp[2] * tmp[1]) / 2;
		total_area = abs(total_area);
		area1 = abs(area1);
		area2 = abs(area2);
		area3 = abs(area3);

		if(area1 + area2 + area3 == total_area) res++;
	}
	cout<<res<<endl;

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Solve();
	return 0;
}
