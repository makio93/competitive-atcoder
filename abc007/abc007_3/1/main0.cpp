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

typedef pair<int, int> P;

int main(){
    int r, c;
    cin >> r >> c;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    --sy; --sx; --gy; --gx;
    vs cs(r);
    rep(i, r) cin >> cs[i];
    vector<vi> d(r, vi(c, INF));
    vi dx = { -1, 1, 0, 0 }, dy = { 0, 0, -1, 1 };
    queue<P> q;
    q.push({sx, sy});
    d[sy][sx] = 0;
    while (!q.empty()) {
        P p = q.front(); q.pop();
        rep(i, 4) {
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (nx>0&&nx<c-1&&ny>0&&ny<r-1&&cs[ny][nx]=='.'&&d[ny][nx]==INF) {
                q.push({nx, ny});
                d[ny][nx] = d[p.second][p.first] + 1;
            }
        }
    }
    cout << d[gy][gx] << endl;
    return 0;
}
