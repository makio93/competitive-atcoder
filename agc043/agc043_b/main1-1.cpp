// 解説AC1

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
    int n;
    cin >> n;
    vi a(n);
    bool one = false;
    rep(i, n) {
        char c;
        cin >> c;
        a[i] = c - '0';
        a[i]--;
        if (a[i]%2==1) one = true;
    }
    if (!one) {
        rep(i, n) a[i] /= 2;
    }
    int ans = a[0] % 2;
    int num = 0, den = 0;
    for (int i=1; i<n; i++) {
        int fact = n - i;
        int factr = i;
        while (fact%2==0) {
            ++num;
            fact /= 2;
        }
        while (factr%2==0) {
            ++den;
            factr /= 2;
        }
        if (den>=num) ans = (ans + a[i]) % 2;
    }
    if (!one) ans *= 2;
    cout << ans << endl;
    return 0;
}
