// 解説AC

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

const string YES = "Yes";
const string NO = "No";

int main(){
    int n;
    cin >> n;
    vi v(3);
    rep(i, 3) cin >> v[i];
    vpii q(n);
    rep(i, n) {
        string s;
        cin >> s;
        q[i].first = (int)(s[0] - 'A');
        q[i].second = (int)(s[1] - 'A');
    }
    q.emplace_back(0, 1);
    string ans;
    auto move = [&] (int to, int from) {
        v[to]++;
        v[from]--;
        ans += to + 'A';
    };
    bool ok = true;
    rep(i, n) {
        int v1 = q[i].first, v2 = q[i].second;
        if (v[v1]==0&&v[v2]==0) {
            ok = false;
            break;
        }
        if (v[v1]==0) {
            move(v1, v2);
        }
        else if (v[v2]==0) {
            move(v2, v1);
        }
        else {
            int nv1 = q[i+1].first, nv2 = q[i+1].second;
            if (nv1==v1||nv2==v1) {
                move(v1, v2);
            }
            else {
                move(v2, v1);
            }
        }
    }
    if (ok) {
        cout << YES << endl;
        rep(i, n) cout << ans[i] << endl;
    }
    else {
        cout << NO << endl;
    }
    return 0;
}
