// 自力,WA

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

#define INF (1e19)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

const ull am = ((ull)1e16+1000);

int main(){
    ull k;
    cin >> k;
    int nt = 2, n = 1, tmp = 100;
    while (nt <= 50) {
        if (k%nt!=0&&am%(nt+1)<(ull)tmp) {
            tmp = am % (nt+1);
            n = nt;
        }
        ++nt;
    }
    vector<ull> a(n);
    if (k >= (ull)n) {
        rep(i, n) a[i] = (k + n) / (n+1) * (n+1) - k;
        k -= (k + n) / (n+1) * n;
    }
    a[0] += k * (n+1);
    cout << n << endl;
    rep(i, n) printf("%llu%c", a[i], (i<n-1?' ':'\n'));
    return 0;
}
