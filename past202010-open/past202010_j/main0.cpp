// バチャ本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const string warp = "ABC";

int main(){
    int n, m;
    cin >> n >> m;
    vi x(3);
    rep(i, 3) cin >> x[i];
    vector<vi> x2(3, vi(3));
    x2[0][1] = x2[1][0] = x[0];
    x2[0][2] = x2[2][0] = x[1];
    x2[1][2] = x2[2][1] = x[2];
    string s;
    cin >> s;
    vector<map<int, int>> wc(3);
    rep(i, n) {
        rep(j, 3) {
            if (s[i] != warp[j]) continue;
            rep(j2, 3) {
                if (j2 == j) continue;
                wc[j2][i] = x2[j2][j];
            }
        }
    }
    vector<vpii> g(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    vector<bool> used(3);
    vll dist(n, INF2);
    q.emplace(0, 0);
    dist[0] = 0;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        ll d = p.first;
        int v = p.second;
        if (d != dist[v]) continue;
        for (auto p2 : g[v]) {
            int to = p2.first, tcost = p2.second;
            ll nd = d + tcost;
            if (dist[to] < nd) continue;
            q.emplace(nd, to);
            dist[to] = nd;
        }
        if (!used[(int)(s[v]-'A')]) {
            for (auto p2 : wc[(int)(s[v]-'A')]) {
                int to = p2.first, tcost = p2.second;
                ll nd = d + tcost;
                if (dist[to] < nd) continue;
                q.emplace(nd, to);
                dist[to] = nd;
            }
            used[(int)(s[v]-'A')] = true;
        }
    }
    cout << dist[n-1] << endl;
    return 0;
}
