// バチャ本番AC

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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct P {
    int y, x;
    P(int y, int x) : y(y), x(x) {}
};

int main(){
    int n, m;
    cin >> n >> m;
    vs a(n);
    rep(i, n) cin >> a[i];
    int sy, sx, gy, gx;
    rep(i, n) rep(j, m) {
        if (a[i][j]=='S') { sy = i; sx = j; }
        if (a[i][j]=='G') { gy = i; gx = j; }
    }
    queue<P> q;
    vector<vector<pair<char, int>>> dist(n, vector<pair<char, int>>(m, {'0'-1, INF}));
    auto ps = [&] (P p, char s, int d) {
        int y = p.y, x = p.x;
        if (y<0 || y>=n || x<0 || x>=m) return;
        char ds = dist[y][x].first;
        int dd = dist[y][x].second;
        char as = a[y][x];
        if (as=='S'||as=='G') as = '0';
        if (as==s+1) ++s;
        if (s < ds) return;
        if (s==ds && d>=dd) return;
        q.push(p);
        dist[y][x].first = s;
        dist[y][x].second = d;
    };
    const int dy[] = { -1, 0, 1, 0 }, dx[] = { 0, 1, 0, -1 };
    ps(P(sy, sx), '0', 0);
    while (!q.empty()) {
        P p = q.front(); q.pop();
        char ns = dist[p.y][p.x].first;
        int nd = dist[p.y][p.x].second + 1;
        rep(i, 4) {
            int ny = p.y + dy[i], nx = p.x + dx[i];
            ps(P(ny, nx), ns, nd);
        }
    }
    if (dist[gy][gx].first!='9') cout << -1 << endl;
    else cout << dist[gy][gx].second << endl;
    return 0;
}
