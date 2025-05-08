#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int int64_t
#define fi first
#define se second
#define mp make_pair
#define max max<int>
#define min min<int>
#define all(a) a.begin(),a.end()
#define sz(a) (signed)a.size()
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e6+10;

int p[MN];

signed main() {
    hyper;
    string s;
    cin >> s;

    string t = "!#";
    for(char c: s) {
        t += c;
        t += '#';
    }
    t += '?';

    int c = 0, r = 0;
    int mx = -1, mxi;
    rep(i,1,sz(t)-1) {
        p[i] = (i < r) ? min(p[2*c-i], r-i) : 1;
        while(t[i-p[i]] == t[i+p[i]]) p[i]++;
        if(i+p[i] > r) {
            r = i+p[i];
            c = i;
        }
        if(p[i]-1 > mx) {
            mx = p[i]-1;
            mxi = i;
        }
    }
    cout << s.substr((mxi-mx)/2, mx);
}
