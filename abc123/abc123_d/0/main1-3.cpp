// 解説AC3

#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e17)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct Rank {
    int x, y, z;
    Rank(int x, int y, int z) : x(x), y(y), z(z) {}
    bool operator<(const Rank& a) const {
        return (x < a.x);
    }
};

int main(){
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vll a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    RSORT(a); RSORT(b); RSORT(c);
    a.pb(-INF); b.pb(-INF); c.pb(-INF);
    priority_queue<pair<ll, Rank>> q;
    set<int> s;
    auto ps = [&] (ll abc, Rank r) {
        int hash = (r.x<<20) + (r.y<<10) + r.z;
        if (s.find(hash)!=s.end()) return;
        q.push({abc, r});
        s.insert(hash);
    };
    vll ans;
    ps(a[0]+b[0]+c[0], {0, 0, 0});
    rep(i, k) {
        auto p = q.top(); q.pop();
        ans.pb(p.first);
        rep(j, 3) {
            int tx = p.second.x;
            int ty = p.second.y;
            int tz = p.second.z;
            if (j==0) ++tx;
            if (j==1) ++ty;
            if (j==2) ++tz;
            ps(a[tx]+b[ty]+c[tz], {tx, ty, tz});
        }
    }
    rep(i, k) cout << ans[i] << endl;
    return 0;
}
