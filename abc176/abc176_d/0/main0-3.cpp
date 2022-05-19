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
    queue<pii> q, q2;
    vector<vi> dist(h, vi(w, INF));
    q2.emplace(ch, cw);
    q.emplace(ch, cw);
    dist[ch][cw] = 0;
    while (!q2.empty()) {
        auto p = q2.front(); q2.pop();
        int y = p.first, x = p.second;
        const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
        rep(i, 4) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny<0||ny>=h||nx<0||nx>=w) continue;
            if (s[ny][nx] == '#') continue;
            if (dist[ny][nx] == 0) continue;
            q2.emplace(ny, nx);
            q.emplace(ny, nx);
            dist[ny][nx] = 0;
        }
    }
    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int y = p.first, x = p.second, d = dist[y][x];
        const vi dy2 = { -2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2 };
        const vi dx2 = { -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2 };
        rep(i, sz(dy2)) {
            int ny = y + dy2[i], nx = x + dx2[i], nd = d+1;
            if (ny<0||ny>=h||nx<0||nx>=w) continue;
            if (s[ny][nx] == '#') continue;
            if (dist[ny][nx] <= nd) continue;
            q2.emplace(ny, nx);
            q.emplace(ny, nx);
            dist[ny][nx] = nd;
            while (!q2.empty()) {
                auto p2 = q2.front(); q2.pop();
                int y2 = p2.first, x2 = p2.second, d2 = dist[y2][x2];
                const vi dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
                rep(j, 4) {
                    int ny2 = y2 + dy[j], nx2 = x2 + dx[j];
                    if (ny2<0||ny2>=h||nx2<0||nx2>=w) continue;
                    if (s[ny2][nx2] == '#') continue;
                    if (dist[ny2][nx2] <= d2) continue;
                    q2.emplace(ny2, nx2);
                    q.emplace(ny2, nx2);
                    dist[ny2][nx2] = d2;
                }
            }
        }
    }
    if (dist[dh][dw] != INF) cout << dist[dh][dw] << endl;
    else cout << -1 << endl;
    return 0;
}
