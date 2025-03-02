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
const int MN = 2e5+5;

int n, r[MN];
struct Customer {
    int s, t, id;
    bool operator<(const Customer &rhs) const {
        if(s != rhs.s) return s < rhs.s;
        return t < rhs.t;
    }
};
Customer a[MN];
priority_queue<pii,vector<pii>,greater<pii>> pq;

signed main() {
    hyper;
    cin >> n;
    rep(i,0,n) {
        cin >> a[i].s >> a[i].t;
        a[i].id = i;
    }
    sort(a,a+n);
    rep(i,0,n) {
        int t;
        if(sz(pq) && pq.top().fi < a[i].s) {
            t = pq.top().se; pq.pop();
        } else {
            t = sz(pq)+1;
        }
        pq.emplace(a[i].t, t);
        r[a[i].id] = t;
    }
    cout << sz(pq) << '\n';
    rep(i,0,n) cout << r[i] << ' ';
    cout << '\n';
}
