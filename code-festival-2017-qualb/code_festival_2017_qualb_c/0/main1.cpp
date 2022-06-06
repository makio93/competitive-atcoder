// 解説AC

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

vector<vi> g;
vi color;
bool dfs(int v, int c = 0) {
    color[v] = c;
    for (int t : g[v]) {
        if (color[t] == 1-c) continue;
        if (color[t] == c) return false;
        if (!dfs(t, 1-c)) return false;
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;
    g = vector<vi>(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    color = vi(n, -1);
    if (dfs(0)) {
        int b = 0, w = 0;
        rep(i, n) {
            if (color[i] == 1) ++w;
            else ++b;
        }
        cout << ((ll)b * w - m) << endl;
    }
    else cout << ((ll)n * (n-1) / 2 - m) << endl;
    return 0;
}
