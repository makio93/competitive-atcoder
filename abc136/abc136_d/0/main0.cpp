// 自力AC

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
    string s;
    cin >> s;
    int n = sz(s);
    vi ans(n);
    vector<pair<pii, int>> rl;
    bool isr = true;
    pii cnt = { 0, 0 };
    rep(i, n) {
        if (!isr && s[i]=='R') {
            isr = true;
            rl.emplace_back(cnt, i);
            cnt = { 0, 0 };
        }
        if (s[i]=='R') ++cnt.first;
        else {
            ++cnt.second;
            isr = false;
        }
    }
    rl.emplace_back(cnt, n);
    rep(i, sz(rl)) {
        int ri = rl[i].second - rl[i].first.second - 1, li = ri+1;
        ans[ri] = (rl[i].first.first+1)/2 + (rl[i].first.second)/2;
        ans[li] = (rl[i].first.second+1)/2 + (rl[i].first.first)/2;
    }
    rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    return 0;
}
