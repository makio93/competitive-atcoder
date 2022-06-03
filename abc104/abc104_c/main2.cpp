// 解説AC2

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

int d, g;
vi p, c;
int dfs(int v, int s) {
    if (v == d) {
        int total = 0, cnt = 0;
        repr(i, v) {
            if (s&(1<<i)) {
                total += (i+1) * 100 * p[i];
                total += c[i];
                cnt += p[i];
            }
        }
        int i = v-1;
        while (i >= 0 && s&(1<<i)) --i;
        if (i < 0) return cnt;
        int j = p[i];
        while (total < g) {
            total += (i+1) * 100;
            ++cnt;
            --j;
            if (j == 0) {
                total += c[i];
                --i;
                while (i >= 0 && s&(1<<i)) --i;
                if (i < 0) return cnt;
                j = p[i];
            }
        }
        return cnt;
    }
    if (v == d-1) return dfs(v+1, s);
    s |= (1<<v);
    int cnt = dfs(v+1, s);
    s &= ~(1<<v);
    cnt = min(cnt, dfs(v+1, s));
    return cnt;
}

int main(){
    cin >> d >> g;
    rep(i, d) {
        int pi, ci;
        cin >> pi >> ci;
        p.push_back(pi);
        c.push_back(ci);
    }
    cout << dfs(0, 0) << endl;
    return 0;
}
