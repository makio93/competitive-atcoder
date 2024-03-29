// 学習1回目,解説AC2

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
    vector<pair<char, int>> rl;
    rl.emplace_back('R', 0);
    rep(i, n) {
        if (s[i] != rl.back().first) rl.emplace_back(s[i], 0);
        rl.back().second++;
    }
    vi ans(n);
    int pos = 0;
    for (int i=0; i<sz(rl); i+=2) {
        int cnt = rl[i].second + rl[i+1].second;
        pos += rl[i].second;
        if (rl[i].second%2==0) {
            ans[pos-1] += cnt/2;
            ans[pos] += (cnt+1)/2;
        }
        else {
            ans[pos-1] += (cnt+1)/2;
            ans[pos] += cnt/2;
        }
        pos += rl[i+1].second;
    }
    rep(i, n) printf("%d%c", ans[i], (i<n-1?' ':'\n'));
    return 0;
}
