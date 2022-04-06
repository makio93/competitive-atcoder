// 自力4,TLE

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

struct ColSet {
    unordered_map<int, int> cset;
    ColSet() {}
    ColSet(unordered_map<int, int> cset_) : cset(cset_) {}
    int sum() {
        int res = 0;
        for (auto& pi : cset) res += pi.second / 2;
        return res;
    }
    ColSet operator+(const ColSet& cs) const {
        unordered_map<int, int> sset;
        if (cset.size() >= cs.cset.size()) {
            sset = cset;
            for (auto& pi : cs.cset) sset[pi.first] += pi.second;
        }
        else {
            sset = cs.cset;
            for (auto& pi : cset) sset[pi.first] += pi.second;
        }
        return sset;
    }
    ColSet operator-(const ColSet& cs) const {
        unordered_map<int, int> sset;
        if (cset.size() >= cs.cset.size()) {
            sset = cset;
            for (auto& pi : cs.cset) sset[pi.first] -= pi.second;
        }
        else {
            sset = cs.cset;
            for (auto& pi : cset) sset[pi.first] -= pi.second;
        }
        return sset;
    }
    ColSet &operator+=(const ColSet& cs) {
        for (auto& pi : cs.cset) cset[pi.first] += pi.second;
        return *this;
    }
};

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
        T x;
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
    int n, q;
    cin >> n;
    vector<int> a(n);
    BIT<ColSet> bit(n+1);
    rep(i, n) {
        cin >> a[i];
        ColSet cs;
        cs.cset[a[i]]++;
        bit.add(i+1, cs);
    }
    cin >> q;
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        ++ri;
        cout << bit.sum(li, ri).sum() << endl;
    }
    return 0;
}
