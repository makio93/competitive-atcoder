// 自力,解けない

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

int dfs(multiset<int> l, vi tar) {
    bool ok = true;
    for (int i : tar) {
        if (l.find(i) == l.end()) ok = false;
    }
    if (ok) return 0;
    ll res = INF;
    auto itr1 = l.begin(), itr2 = itr1;
    for (++itr2; itr2!=l.end(); ++itr2) {
        auto itr3 = itr2;
        for (++itr3; itr3!=l.end(); ++itr3) {
            multiset<int> l1, l2, l3;
            auto itr = l.begin();
            for (itr=itr1; itr!=itr2; ++itr) {
                l1.insert(*itr);
            }
            for (itr=itr2; itr!=itr3; ++itr) {
                l2.insert(*itr);
            }
            for (itr=itr3; itr!=l.end(); ++itr) {
                l3.insert(*itr);
            }
            vi tar2 = tar;
            do {
            } while (next_permutation(all(tar2)));
        }
    }
    return res;
}

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    multiset<int> l;
    rep(i, n) {
        int li;
        cin >> li;
        l.insert(li);
    }
    cout << dfs(l, {a,b,c}) << endl;
    return 0;
}
