// 本番WA

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

using mint = modint;

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        ll n, s, k;
        cin >> n >> s >> k;
        if (gcd(n, k) != 1) {
            if (n%k == 0) {
                if ((n-s)%k == 0) cout << ((n-s) / k) << endl;
                else cout << -1 << endl;
            }
            else {
                ll val = s;
                ll cnt = (n - val) / k;
                val += (n - val) / k * k;
                ll minus = (k - n % k), plus = n % k;
                ll add = min((val)/minus, (n-(val+k)%n)/k+1);
                cnt += add;
                /*
                while (cnt<=n && val%n!=0) {
                    val += k;
                    ++cnt;
                    val %= n;
                    cnt += (n - val) / k;
                    val += ((n - val) / k * k);
                }
                */
                //if (cnt > n) cout << -1 << endl;
                cout << cnt << endl;
            }
        }
        else {
            mint::set_mod(n);
            mint val = n - s;
            val /= k;
            cout << val.val() << endl;
        }
    }
    return 0;
}
