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

vector<int> pre(string s) {
    int n = sz(s);
    int i = 0, j = -1;
    vector<int> pi(n+1, -1);
    while (i < n) {
        if (j == -1 || s[i] == s[j]) {
            ++i; ++j;
            pi[i] = j;
        } else {
            j = pi[j];
        }
    }
    return pi;
}

int kmp(string s, string p) {
    int n = sz(s), m = sz(p);
    int i = 0, j = 0;
    int cnt = 0;
    vector<int> pi = pre(p);
    while (i < n) {
        if (j == -1 || s[i] == p[j]) {
            ++i, ++j;
        } else {
            if(j == m) ++cnt;
            j = pi[j];
        }
    }
    if(j == m) ++cnt;
    return cnt;
}

signed main() {
    hyper;
    string s, p;
    cin >> s >> p;
    cout << kmp(s, p) << '\n';
}
