// 本番AC

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

bool mt[101][101];
int cnt[101][101];

int main(){
    int h, w;
    cin >> h >> w;
    rep1(i, h) {
        rep1(j, w) {
            char m;
            cin >> m;
            if (m=='.') mt[i][j] = true;
        }
    }
    for (int i=2; i<=w+h; i++) {
        for (int ch=1; ch<i; ch++) {
            int cw = i - ch;
            if (cw > w || ch > h) continue;
            if (ch==1&&cw==1) 
                cnt[ch][cw] = mt[ch][cw]?0:1;
            else if (ch==1) 
                cnt[ch][cw] = (mt[ch][cw]==mt[ch][cw-1])?cnt[ch][cw-1]:(cnt[ch][cw-1]+1);
            else if (cw==1) 
                cnt[ch][cw] = (mt[ch][cw]==mt[ch-1][cw])?cnt[ch-1][cw]:(cnt[ch-1][cw]+1);
            else {
                int right = (mt[ch][cw]==mt[ch][cw-1])?cnt[ch][cw-1]:(cnt[ch][cw-1]+1);
                int height = (mt[ch][cw]==mt[ch-1][cw])?cnt[ch-1][cw]:(cnt[ch-1][cw]+1);
                cnt[ch][cw] = min(right, height);
            }
        }
    }
    int ans = (cnt[h][w] + 1) / 2;
    cout << ans << endl;
    return 0;
}
