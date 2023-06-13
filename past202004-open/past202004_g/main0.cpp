// バチャ本番AC

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

int main(){
    int qn;
    cin >> qn;
    queue<pair<char, ll>> q;
    rep(i, qn) {
        int t;
        cin >> t;
        if (t==1) {
            char c;
            int x;
            cin >> c >> x;
            if (!q.empty() && q.back().first==c) q.back().second += x;
            else q.emplace(c, x);
        }
        else {
            int d;
            cin >> d;
            map<char, ll> cnt;
            while (d>0 && !q.empty()) {
                ll sub = min(ll(d), q.front().second);
                cnt[q.front().first] += sub;
                q.front().second -= sub;
                d -= sub;
                if (q.front().second==0) q.pop();
            }
            ll ans = 0;
            for (auto p : cnt) {
                ans += p.second * p.second;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
