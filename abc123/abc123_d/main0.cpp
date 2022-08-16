// 自力AC

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

#define INF (1e17)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

struct P {
    int x, y, z;
    P(int x, int y, int z) : x(x), y(y), z(z) {}
    bool operator<(const P& a) const {
        return x < a.x;
    }
};

int main(){
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vll a(x+1);
    rep(i, x) cin >> a[i];
    a[x] = -INF;
    vll b(y+1);
    rep(i, y) cin >> b[i];
    b[y] = -INF;
    vll c(z+1);
    rep(i, z) cin >> c[i];
    c[z] = -INF;
    RSORT(a); RSORT(b); RSORT(c);
    priority_queue<pair<ll, P>> q;
    //map<ll, bool> used;
    auto push = [&] (ll v, P p) {
        if (p.x>x||p.y>y||p.z>z) return;
        //if (used[p.x*p.y*p.z]) return;
        q.emplace(v, p);
        //used[p.x*p.y*p.z] = true;
    };
    P s(0, 0, 0);
    push(a[0]+b[0]+c[0], P(0, 0, 0));
    rep(i, k) {
        auto p = q.top(); q.pop();
        cout << p.first << endl;
        if (p.second.x==s.x) {
            ++(s.x);
            rep(j, s.y+1) {
                rep(h, s.z+1) {
                    ll v = a[s.x] + b[j] + c[h];
                    push(v, P(s.x, j, h));
                }
            }
        }
        if (p.second.y==s.y) {
            ++(s.y);
            rep(j, s.x+1) {
                rep(h, s.z+1) {
                    ll v = a[j] + b[s.y] + c[h];
                    push(v, P(j, s.y, h));
                }
            }
        }
        if (p.second.z==s.z) {
            ++(s.z);
            rep(j, s.x+1) {
                rep(h, s.y+1) {
                    ll v = a[j] + b[h] + c[s.z];
                    push(v, P(j, h, s.z));
                }
            }
        }
    }
    return 0;
}
