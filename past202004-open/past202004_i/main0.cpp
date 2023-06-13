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

struct SEG {
    int n;
    vpii data;
    SEG(int n) : n(n), data(2*n-1, {0, -1}) {}
    void update(int k, int a) {
        k += n - 1;
        data[k].first = a;
        data[k].second = k - (n - 1);
        while (k > 0) {
            k = (k - 1) / 2;
            data[k].first = max(data[k*2+1].first, data[k*2+2].first);
            bool lar = (data[k*2+1].first > data[k*2+2].first);
            data[k].second = (lar?data[k*2+1].second:data[k*2+2].second);
        }
    }
};

int main(){
    int n, n2 = 1;
    cin >> n;
    rep(i, n) n2 *= 2;
    vi a(n2);
    rep(i, n2) cin >> a[i];
    SEG sg(n2);
    rep(i, n2) sg.update(i, a[i]);
    vi ans(n2);
    int tar = 2, val = n + 1;
    rep1(i, sz(sg.data)-1) {
        if (i+1>=tar) {
            tar <<= 1;
            --val;
        }
        ans[sg.data[i].second] = max(ans[sg.data[i].second], val);
    }
    rep(i, n2) cout << ans[i] << endl;
    return 0;
}
