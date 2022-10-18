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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

string s;
vector<char> ans(3);
void dfs(int i, int sum, vector<char> c) {
    if (i == 3) {
        if (sum == 7) ans = c;
        return;
    }
    c[i] = '+';
    dfs(i+1, sum+(s[i+1]-'0'), c);
    c[i] = '-';
    dfs(i+1, sum-(s[i+1]-'0'), c);
}

int main(){
    cin >> s;
    int sum = s[0] - '0';
    vector<char> c(3);
    dfs(0, sum, c);
    cout << s[0];
    rep(i, 3) cout << ans[i] << s[i+1];
    cout << "=7" << endl;
    return 0;
}
