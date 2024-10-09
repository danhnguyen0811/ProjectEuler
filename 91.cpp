#include<bits/stdc++.h>

//simply brute-force
using namespace std;

const int N = 50;

void Solve(){
	int res = 0;
	for(double x = 0; x <= N; x++){
		for(double y = 0; y <= N; y++){
			for(double a = 0; a <= N; a++){
				for(double b = 0; b <= N; b++){
					double l1 = sqrt(x * x + y * y);
					double l2 = sqrt(a * a + b * b);
					double l3 = sqrt((a - x) * (a - x) + (b - y) * (b - y));
					//cout<<l1<<" "<<l2<<" "<<l3<<endl;
					if(l1 <= 0.001 || l2 <= 0.001 || l3 <= 0.001) continue;
					bool valid = false;
					if(abs(l1 * l1 + l2 * l2 - l3 * l3) <= 0.001) valid = true;
					if(abs(l1 * l1 + l3 * l3 - l2 * l2) <= 0.001) valid = true;
					if(abs(l2 * l2 + l3 * l3 - l1 * l1) <= 0.001) valid = true;
					if(valid) res++;
				}
			}
		}
	}
	cout<<res / 2<<endl;

}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Solve();
	return 0;
}
