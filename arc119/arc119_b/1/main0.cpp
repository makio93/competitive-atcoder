// 学習1回目,自力WA

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0) : n(n), d(n+1) {}
    void add(int i, T x=1) {
        for (i++; i<=n; i+=i&-i) {
            d[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i-=i&-i) {
            x += d[i];
        }
        return x;
    }
    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    if (count(all(s), '1') != count(all(t), '1')) {
        cout << -1 << endl;
        return 0;
    }
    BIT<int> zsum(n);
    rep(i, n) if (s[i] == '0') zsum.add(i);
    vector<int> sids, tids;
    rep(i, n) {
        if (s[i] == '1') sids.push_back(i);
        if (t[i] == '1') tids.push_back(i);
    }
    ll res = 0;
    int m = sids.size();
    rep(i, m) {
        if (sids[i] != tids[i]) {
            int li = sids[i], ri = tids[i];
            if (ri < li) swap(li, ri);
            ++ri;
            res += zsum.sum(li, ri);
            zsum.add(sids[i], 1);
            zsum.add(tids[i], -1);
        }
    }
    cout << res << endl;
    return 0;
}
