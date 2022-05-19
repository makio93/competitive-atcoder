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
    int ch, cw, dh, dw;
    cin >> ch >> cw >> dh >> dw;
    --ch; --cw; --dh; --dw;
    vs s(h);
    rep(i, h) cin >> s[i];
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
    vector<vi> dist(h, vi(w, INF));
    q.push({0, {ch, cw}});
    dist[ch][cw] = 0;
    while (!q.empty()) {
        auto p = q.top(); q.pop();
        int y = p.second.first, x = p.second.second, d = p.first;
        if (d != dist[y][x]) continue;
        const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        rep(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny<0||ny>=h||nx<0||nx>=w) continue;
            if (s[ny][nx] == '#') continue;
            if (dist[ny][nx] <= d) continue;
            q.push({d, {ny, nx}});
            dist[ny][nx] = d;
        }
        const vi dy2 = { -2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
        const vi dx2 = { -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2 };
        rep(i, sz(dy2)) {
            int ny = y + dy2[i], nx = x + dx2[i], nd = d+1;
            if (ny<0||ny>=h||nx<0||nx>=w) continue;
            if (s[ny][nx] == '#') continue;
            if (dist[ny][nx] <= nd) continue;
            q.push({nd, {ny, nx}});
            dist[ny][nx] = nd;
        }
    }
    if (dist[dh][dw] != INF) cout << dist[dh][dw] << endl;
    else cout << -1 << endl;
    return 0;
}
