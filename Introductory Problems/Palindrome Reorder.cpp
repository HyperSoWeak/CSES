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
const int MN = 1e6+5;

signed main() {
    hyper;
    string s;
    cin >> s;
    int cnt[26] = {0};
    for(char c: s) cnt[c-'A']++;
    int odd = -1;
    rep(i,0,26) if(cnt[i]&1) {
        if(odd != -1) {
            cout << "NO SOLUTION\n";
            return 0;
        }
        odd = i;
    }
    rep(i,0,26) if(!(cnt[i]&1)) rep(j,0,cnt[i]/2) cout << (char)(i+'A');
    if(odd != -1) rep(j,0,cnt[odd]) cout << (char)(odd+'A');
    for(int i=25; i>=0; --i) if(!(cnt[i]&1)) rep(j,0,cnt[i]/2) cout << (char)(i+'A');
    cout << '\n';
}
