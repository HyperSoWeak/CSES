#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using mat = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 25;

string s[8];
int cnt = 0, pos[8];

bool check(int x, int y) {
    if(s[x][y] == '*') return 0;
    rep(i,0,x) if(pos[i] == y || abs(x-i) == abs(y-pos[i])) return 0;
    return 1;
}

void solve(int x) {
    if(x == 8) {
        cnt++;
        return;
    }
    rep(y,0,8) {
        if(check(x,y)) {
            pos[x] = y;
            solve(x+1);
        }
    }
}

signed main() {
    hyper;
    rep(i,0,8) cin >> s[i];
    solve(0);
    cout << cnt << '\n';
}
