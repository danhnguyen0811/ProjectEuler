#include<bits/stdc++.h>

// the idea is not that hard but the implementation part is painful
using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

typedef long long ll;

vector<vector<char>> d;
vector<vector<char>> operators;
vector<char> v;
vector<char> avai = {'+', '-', '*', '/'};
vector<char> v1;
vector<string> s;
vector<char> digits;

void backtrack(){
    if(v.size() == 4){
        d.push_back(v);
        return;
    }
    for(char i: digits){
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
void backtrack2(){
    if(v.size() == 3){
        operators.push_back(v);
        return;
    }
    for(char c: avai){
        v.push_back(c);
        backtrack2();
        v.pop_back();
    }
}
void Solve(){
    backtrack2();
    int max_mex = 0;
    string result = "";
    for(int aa = 1; aa < 9; aa++){
        for(int bb = aa + 1; bb < 9; bb++){
            for(int cc = bb + 1; cc < 9; cc++){
                for(int dd = cc + 1; dd <= 9; dd++){
                    d.clear();
                    v.clear();
                    s.clear();
                    digits = {aa + '0', bb + '0', cc + '0', dd + '0'};
                    backtrack();
                    for(auto x: d){
                        for(auto y: operators){
                            string t = "";
                            for(int i = 0; i < 4; i++){
                                t += x[i];
                                if(i < 3) t += y[i];
                            }
                            s.push_back(t);
                            string k = "";
                            k = "(" + std::string(1, t[0]) + std::string(1, t[1]) + std::string(1, t[2]) + ")" + std::string(1, t[3]) + std::string(1, t[4]) + std::string(1, t[5]) + std::string(1, t[6]);
                            s.push_back(k);

                            k = "(" + std::string(1, t[0]) + std::string(1, t[1]) + std::string(1, t[2]) + ")" + std::string(1, t[3]) + "(" + std::string(1, t[4]) + std::string(1, t[5]) + std::string(1, t[6]) + ")";
                            s.push_back(k);

                            k = "(" + std::string(1, t[0]) + std::string(1, t[1]) + std::string(1, t[2]) + std::string(1, t[3]) + std::string(1, t[4]) + ")" + std::string(1, t[5]) + std::string(1, t[6]);
                            s.push_back(k);

                            k = std::string(1, t[0]) + std::string(1, t[1]) + "(" + std::string(1, t[2]) + std::string(1, t[3]) + std::string(1, t[4]) + ")" + std::string(1, t[5]) + std::string(1, t[6]);
                            s.push_back(k);

                            k = std::string(1, t[0]) + std::string(1, t[1]) + "(" + std::string(1, t[2]) + std::string(1, t[3]) + std::string(1, t[4]) + std::string(1, t[5]) + std::string(1, t[6]) + ")";
                            s.push_back(k);

                            k = std::string(1, t[0]) + std::string(1, t[1]) + std::string(1, t[2]) + std::string(1, t[3]) + "(" + std::string(1, t[4]) + std::string(1, t[5]) + std::string(1, t[6]) + ")";
                            s.push_back(k);
                        }
                    }
                    set<int> ans;
                    map<char, int> pre;
                    pre['+'] = pre['-'] = 1;
                    pre['*'] = pre['/'] = 2;
                    for(auto x: s){
                        stack<double> num;
                        stack<char> op;
                        for(char c: x){
                            if( '1' <= c && c <= '9') num.push(c - '0');
                            else{
                                if(c == '(') op.push(c);
                                else if(c == ')'){
                                    while(!op.empty() && op.top() != '('){
                                        double b = num.top();
                                        num.pop();
                                        double a = num.top();
                                        num.pop();
                                        char opr = op.top();
                                        op.pop();
                                        double c;
                                        if(opr == '+') c = a + b;
                                        if(opr == '-') c = a - b;
                                        if(opr == '*') c = a * b;
                                        if(opr == '/') c = a / b;
                                        num.push(c);
                                    }
                                    op.pop();
                                }
                                else{
                                    while(!op.empty() && pre[op.top()] >= pre[c]){
                                        double b = num.top();
                                        num.pop();
                                        double a = num.top();
                                        num.pop();
                                        char opr = op.top();
                                        op.pop();
                                        double c;
                                        if(opr == '+') c = a + b;
                                        if(opr == '-') c = a - b;
                                        if(opr == '*') c = a * b;
                                        if(opr == '/') c = a / b;
                                        num.push(c);
                                    }
                                    op.push(c);
                                }
                            }
                        }
                        while(!op.empty()){
                            double b = num.top();
                            num.pop();
                            double a = num.top();
                            num.pop();
                            char opr = op.top();
                            op.pop();
                            double c;
                            if(opr == '+') c = a + b;
                            if(opr == '-') c = a - b;
                            if(opr == '*') c = a * b;
                            if(opr == '/') c = a / b;
                            num.push(c);
                        }
                        double res = num.top();
                        int int_res = res;
                        if((double)int_res == res && int_res > 0) ans.insert(int_res);
                        //cout<<x<<" "<<res<<" "<<int_res<<nl;
                    }
                    vector<bool> mex(1000);
                    while(!ans.empty()){
                        mex[*ans.begin()] = true;
                        ans.erase(ans.begin());
                    }
                    int cur_max = 0;
                    for(int i = 1; i < 1000; i++){
                        if(!mex[i]){
                            cur_max = i - 1;
                            break;
                        }
                    }
                    if(cur_max > max_mex){
                        max_mex = cur_max;
                        string tmp = "";
                        tmp += aa + '0';
                        tmp += bb + '0';
                        tmp += cc + '0';
                        tmp += dd + '0';
                        result = tmp;
                    }
                }
            }
        }
    }
    cout<<result<<" "<<max_mex<<nl;

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
