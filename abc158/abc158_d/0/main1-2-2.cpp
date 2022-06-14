// 解説AC2-2

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
    string in;
    cin >> in;
    deque<char> s;
    for (char c : in) s.push_back(c);
    bool flip = false;
    int q;
    cin >> q;
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 1) {
            flip = !flip;
        }
        else {
            int f;
            char c;
            cin >> f >> c;
            if (flip) f = 3 - f;
            if (f == 1) s.push_front(c);
            else s.push_back(c);
        }
    }
    if (flip) reverse(all(s));
    string ans;
    for (char c : s) {
        ans += c;
    }
    cout << ans << endl;
    return 0;
}
