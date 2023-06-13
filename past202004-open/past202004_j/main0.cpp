// バチャ本番WA

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
    string s;
    cin >> s;
    list<char> ls;
    rep(i, sz(s)) ls.pb(s[i]);
    stack<list<char>::iterator> st;
    auto itr = ls.begin();
    while (itr!=ls.end()) {
        if (*itr=='(') {
            st.push(itr);
            ++itr;
        }
        else if (*itr==')') {
            list<char> ts;
            auto itrb = st.top(); st.pop();
            auto itre = itr;
            itre = ls.erase(itre);
            itrb = ls.erase(itrb);
            ts.insert(ts.begin(), itrb, itre);
            itre = ls.erase(itrb, itre);
            ls.insert(itre, all(ts));
            ls.insert(itre, rall(ts));
            itr = itre;
        }
        else ++itr;
    }
    auto itr2 = ls.begin();
    string ans;
    while (itr2!=ls.end()) {
        ans.pb(*itr2);
        ++itr2;
    }
    cout << ans << endl;
    return 0;
}
