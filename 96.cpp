#include<bits/stdc++.h>

using namespace std;

#define nl '\n'
#define fi first
#define se second
#define pb push_back

// I feel like half of PE problems involved in backtracking, lol
typedef long long ll;

int res = 0;
bool done = false;

vector<vector<char>> sudoku;
vector<pair<int, int>> blank;

bool isValid(int x, int y, char c){
    // vertical line
    for(int i = 0; i < 9; i++){
        if(sudoku[x][i] == c) return false;
    }
    // horizontal line
    for(int i = 0; i < 9; i++){
        if(sudoku[i][y] == c) return false;
    }
    // sub-grid
    int xx = x / 3;
    int yy = y / 3;
    for(int i = xx * 3; i < xx * 3 + 3; i++){
        for(int j = yy * 3; j < yy * 3 + 3; j++){
            if(sudoku[i][j] == c) return false;
        }
    }
    return true;
}
void backtrack(int cur){
    if(done) return;
    if(cur == blank.size()){
        string t = "";
        t += sudoku[0][0];
        t += sudoku[0][1];
        t += sudoku[0][2];
        res += stoi(t);
        done = true;
    }
    for(char c = '1'; c <= '9'; c++){
        if(!isValid(blank[cur].fi, blank[cur].se, c)) continue;
        sudoku[blank[cur].fi][blank[cur].se] = c;
        backtrack(cur + 1);
        sudoku[blank[cur].fi][blank[cur].se] = '0';
    }
}
void Solve(){
    vector<vector<char>> v(9, vector<char> (9));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin>>v[i][j];
            if(v[i][j] == '0') blank.push_back({i, j});
        }
    }
    sudoku = v;
    backtrack(0);
    done = false;
    blank.clear();

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b;
    while(cin>>a && cin>>b){
        Solve();
    }
    cout<<res<<nl;
}
