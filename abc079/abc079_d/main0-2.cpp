// 自力AC2

#include <bits/stdc++.h>
using namespace std;

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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int h, w;
    cin >> h >> w;
    vector<vi> c(10, vi(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    vector<vi> a(h, vi(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    vector<vpii> g(10);
    rep(i, 10) rep(j, 10) g[i].emplace_back(j, c[j][i]);
    priority_queue<pii, vpii, greater<pii>> q;
    vi dist(10, INF);
    q.emplace(0, 1);
    dist[1] = 0;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        int d = p.first, v = p.second;
        if (d > dist[v]) continue;
        for (auto t : g[v]) {
            int nt = t.first, nd = d + t.second;
            if (nt == v) continue;
            if (dist[nt] <= nd) continue;
            q.emplace(nd, nt);
            dist[nt] = nd;
        }
    }
    int ans = 0;
    rep(i, h) rep(j, w) {
        if (a[i][j] == -1) continue;
        ans += dist[a[i][j]];
    }
    cout << ans << endl;
    return 0;
}
