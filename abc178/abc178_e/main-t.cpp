// 本番,temp

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
    int n;
    cin >> n;
    vpll xy(n);
    rep(i, n) cin >> xy[i].first >> xy[i].second;
    VSORT(xy);
    ll val = llabs(xy[1].first-xy[0].first) + llabs(xy[1].second-xy[0].second);
    pii p = { 0, 1 };
    for (int i=2; i<n; ++i) {
        ll nval1 = llabs(xy[i].first-xy[p.first].first) + llabs(xy[i].second-xy[p.first].second);
        ll nval2 = llabs(xy[i].first-xy[p.second].first) + llabs(xy[i].second-xy[p.second].second);
        if (val >= max(nval1, nval2)) continue;
        if (nval1 >= nval2) {
            val = nval1;
            p.second = i;
        }
        else {
            val = nval2;
            p.first = p.second;
            p.second = i;
        }
    }
    cout << val << endl;
    return 0;
}
