// バチャ本番AC

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, k;
    cin >> n >> k;
    vs s(n);
    rep(i, n) cin >> s[i];
    map<string, int> cnt;
    rep(i, n) cnt[s[i]]++;
    vector<pair<int, string>> ls;
    for (auto p : cnt) {
        ls.emplace_back(p.second, p.first);
    }
    RSORT(ls);
    string ans;
    rep(i, sz(ls)) {
        if (i<k-1) continue;
        if (i==k-1) {
            int val = ls[i].first;
            bool ok = true;
            if (i-1>=0 && val==ls[i-1].first) ok = false;
            if (i+1<sz(ls) && val==ls[i+1].first) ok = false;
            if (ok) cout << ls[i].second << endl;
            else cout << "AMBIGUOUS" << endl;
            return 0;
        }
    }
    return 0;
}
