// 自力AC

#include <bits/stdc++.h>
using namespace std;

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
    int y, m, d;
    scanf("%d%*c%d%*c%d", &y, &m, &d);
    int j = m, k = d;
    for (int i=y; i<=10000; ++i) {
        while (j <= 12) {
            while (1) {
                if (i%j==0 && i/j%k==0) {
                    printf("%4d/%02d/%02d\n", i, j, k);
                    return 0;
                }
                if (j==2) {
                    if (i%1000 && k>=29) break;
                    else if (i%100==0 && k>=28) break;
                    else if (i%4==0 && k>=29) break;
                    else if (i%4!=0 && k>=28) break;
                }
                else {
                    bool full = false;
                    for (int t : { 4, 6, 9, 11 }) {
                        if (j == t) full = true;
                    }
                    if (full && k>=30) break;
                    if (k>=31) break;
                }
                ++k;
            }
            k = 1; ++j;
        }
        j = 1;
    }
    return 0;
}
