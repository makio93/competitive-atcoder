// 本番AC

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

const int q_max = 50;
int n, m, q;
vi a(q_max), b(q_max), c(q_max), d(q_max);
int ans = 0;
vector<bool> used(11);
vi nums(10);
void dfs(int dep, int p) {
    if (dep == n) {
        int sum = 0;
        rep(i, q) {
            if (nums[b[i]]-nums[a[i]]==c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        return;
    }
    for (int i=p; i<=m; ++i) {
        nums[dep] = i;
        dfs(dep+1, i);
    }
}

int main(){
    cin >> n >> m >> q;
    rep(i, q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i]; --b[i];
    }
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}
