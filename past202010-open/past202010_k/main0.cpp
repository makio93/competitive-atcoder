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

const long long mod = 10;

int main(){
    int k;
    cin >> k;
    vector<vi> a(k);
    rep(i, k) {
        int n;
        cin >> n;
        rep(j, n) {
            int ai;
            cin >> ai;
            a[i].pb(ai);
        }
    }
    int q;
    cin >> q;
    vi b(q);
    rep(i, q) {
        cin >> b[i];
        b[i]--;
    }
    vll rev(k);
    vector<vi> nmap(k);
    rep(i, k) {
        vi tcnt(21);
        rep(j, sz(a[i])) {
            int sum = 0;
            for (int j2=a[i][j]+1; j2<=20; ++j2) {
                sum += tcnt[j2];
            }
            rev[i] += sum;
            tcnt[a[i][j]]++;
        }
        nmap[i] = tcnt;
    }
    ll ans = 0;
    vll xmap(21);
    rep(i, q) {
        rep(j, 21) for (int j2=j+1; j2<21; ++j2) {
            ans += (ll)nmap[b[i]][j] * xmap[j2];
        }
        rep(j, 21) xmap[j] += nmap[b[i]][j];
        ans += rev[b[i]];
    }
    ans %= (ll)(1e9);
    cout << ans << endl;
    return 0;
}
