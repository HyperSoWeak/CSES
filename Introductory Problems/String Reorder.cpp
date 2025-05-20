#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int int64_t
#define fi first
#define se second
#define max max<int>
#define min min<int>
#define all(a) a.begin(),a.end()
#define sz(a) (signed)a.size()
#define rr(a,x) memset(a,x,sizeof(a))
#define hyper ios::sync_with_stdio(0); cin.tie(0)
using namespace std;
using pii = pair<int,int>;
using tiii = tuple<int,int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 1005;

string s, t;
int cnt[26];

signed main() {
    hyper;
    cin >> s;
    for(char c: s) cnt[c-'A']++;
    int pre = -1;
    rep(x,0,sz(s)) {
        int mx = -1, mxi, sum = 0;
        rep(i,0,26) {
            if(cnt[i] > mx) {
                mxi = i;
                mx = cnt[i];
            }
            sum += cnt[i];
        }
        if(mx > sum-mx) {
            if(pre == mxi) return cout << "-1\n", 0;
            t += (char)mxi+'A';
            cnt[mxi]--;
            pre = mxi;
            continue;
        }
        int i = 0;
        while(i<26 && cnt[i]==0) i++;
        if(i == 26) return cout << "-1\n", 0;
        if(pre == i) {
            i++;
            while(i<26 && cnt[i]==0) i++;
            if(i == 26) return cout << "-1\n", 0;
        }
        t += (char)i+'A';
        cnt[i]--;
        pre = i;
    }
    cout << t << '\n';
}
