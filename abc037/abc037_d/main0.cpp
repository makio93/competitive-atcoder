// 自力,WA

#include <bits/stdc++.h>
using namespace std;

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

const long long MOD = 1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vi> a(h, vi(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    ll ans = h * w;
    vector<vector<vpii>> dir(h, vector<vpii>(w));
    rep(i, h) rep(j, w) {
        const vi di = { -1, 0, 1, 0 }, dj = { 0, 1, 0, -1 };
        rep(k, 4) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni<0||ni>=h||nj<0||nj>=w) continue;
            if (a[ni][nj] > a[i][j]) dir[i][j].emplace_back(ni, nj);
        }
    }
    vector<vll> dist(h, vll(w, 1));
    vector<vector<bool>> vlist(h, vector<bool>(w, true));
    while (1) {
        vector<vll> ndist(h, vll(w));
        vector<vector<bool>> nvlist(h, vector<bool>(w, false));
        bool exist = false;
        rep(i, h) rep(j, w) {
            if (!vlist[i][j]) continue;
            rep(k, sz(dir[i][j])) {
                int ni = dir[i][j][k].first, nj = dir[i][j][k].second;
                if (ni<0||ni>=h||nj<0||nj>=w) continue;
                ndist[i][j] = (ndist[i][j] +  dist[ni][nj]) % MOD;
            }
            if (ndist[i][j] > 0) {
                ans = (ans + ndist[i][j]) % MOD;
                nvlist[i][j] = true;
                exist = true;
            }
        }
        if (!exist) break;
        swap(ndist, dist);
        swap(nvlist, vlist);
    }
    cout << ans << endl;
    return 0;
}
