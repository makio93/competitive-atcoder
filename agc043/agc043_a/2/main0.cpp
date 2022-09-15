// 学習2回目,自力AC

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
    vs s(h);
    rep(i, h) cin >> s[i];
    queue<pii> q;
    vector<vi> dist(h, vi(w, INF));
    q.emplace(0, 0);
    dist[0][0] = (s[0][0]=='.'?0:1);
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.first, x = p.second, d = dist[y][x];
        const vi dy = { 0, 1 }, dx = { 1, 0 };
        rep(i, 2) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny<0 || ny>=h || nx<0 || nx>=w) continue;
            int nd = d + (s[y][x]!=s[ny][nx]?1:0);
            if (dist[ny][nx] <= nd) continue;
            q.emplace(ny, nx);
            dist[ny][nx] = nd;
        }
    }
    int cnt = dist[h-1][w-1] + (s[h-1][w-1]=='.'?0:1);
    cout << (cnt / 2) << endl;
    return 0;
}
