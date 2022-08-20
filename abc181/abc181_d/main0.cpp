// 本番AC

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
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const string YES = "Yes";
const string NO = "No";

int main(){
    string s;
    cin >> s;
    vi cnt(10);
    rep(i, sz(s)) {
        cnt[s[i]-'0']++;
    }
    int len = min(3, sz(s)), mxval = 1, mnval = 1;
    rep(i, len) mxval *= 10;
    rep(i, len-1) mnval *= 10;
    bool ans = false;
    for (int i=8; i<mxval; i+=8) {
        if (i < mnval) continue;
        vi cnt2 = cnt;
        int t = i;
        bool ok = true;
        while (t > 0) {
            if (t%10 == 0) ok = false;
            if (cnt2[t%10] == 0) ok = false;
            cnt2[t%10]--;
            t /= 10;
        }
        if (ok) ans = true;
    }
    if (ans) cout << YES << endl;
    else cout << NO << endl;
    return 0;
}
