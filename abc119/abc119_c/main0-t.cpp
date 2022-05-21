// 自力,temp

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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int n, a, b, c;
ll dfs(multiset<int> l) {
    if (l.find(a)!=l.end()&&l.find(b)!=l.end()&&l.find(c)!=l.end()) return 0;
    ll res = INF;
    for (auto itr=l.begin(); itr!=l.end(); ++itr) {
        int val = *itr;
        multiset<int> l2 = l;
        l2.erase(l2.find(val));
        if (val+1<=a) {
            l2.insert(val+1);
            res = min(res, dfs(l2)+1);
            l2.erase(l2.find(val+1));
        }
        if (val-1>=1) {
            l2.insert(val-1);
            res = min(res, dfs(l2)+1);
            l2.erase(l2.find(val-1));
        }
        for (int i : { a, b, c }) {
            if (val != i) {
                int vals = abs(val-i);
                l2.insert(i);
                res = min(res, dfs(l2)+vals);
                l2.erase(l2.find(i));
            }
        }
    }
    for (auto itr1=l.begin(); itr1!=l.end(); ++itr1) {
        auto itr2 = itr1;
        for (++itr2; itr2!=l.end(); ++itr2) {
            int val1 = *itr1, val2 = *itr2, val = val1 + val2;
            if (val > a) continue;
            multiset<int> l2 = l;
            l2.erase(l2.find(val1));
            l2.erase(l2.find(val2));
            l2.insert(val);
            res = min(res, dfs(l2)+10);
        }
    }
    return res;
}

int main(){
    cin >> n >> a >> b >> c;
    multiset<int> l;
    rep(i, n) {
        int li;
        cin >> li;
        l.insert(li);
    }
    cout << dfs(l) << endl;
    return 0;
}
